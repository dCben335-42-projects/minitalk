/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:40:12 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/06 21:03:21 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

static void	handle_message(int signal, t_server *server)
{
	server->message[server->char_index] |= (signal == SIGUSR1);
	if (++(server->bit_index) == 8)
	{
		server->bit_index = 0;
		if (++(server->char_index) == server->message_len)
		{
			kill(server->pid, SIGUSR2);
			if (write(1, server->message, server->message_len) == -1
				|| write(1, "\n", 1) == -1)
			{
				free(server->message);
				ft_error(WRITE_ERROR_MSG);
			}
			free(server->message);
			server->is_receiving = false;
		}
	}
	else
		server->message[server->char_index] <<= 1;
}

static void	handle_message_len(int signal, t_server *server)
{
	server->message_len |= (signal == SIGUSR1);
	if (++(server->bit_index) == 32)
	{
		server->bit_index = 0;
		server->is_message_len_received = true;
		server->message = malloc((server->message_len + 1)
				* sizeof(unsigned char));
		if (!server->message)
			ft_error(MALLOC_ERROR_MSG);
		ft_memset(server->message, 0, server->message_len + 1);
	}
	else
		server->message_len <<= 1;
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static t_server	server = {.is_receiving = false};

	if (!server.is_receiving)
	{
		server = (t_server){
			.is_receiving = true, .pid = info->si_pid,
			.bit_index = 0, .char_index = 0,
			.is_message_len_received = false, .message_len = 0, .message = NULL
		};
		kill(server.pid, SIGUSR1);
		return ;
	}
	if (server.pid != info->si_pid)
	{
		if (server.message)
			free(server.message);
		ft_error(DIFFERENT_CLIENT_MSG);
	}
	if (!server.is_message_len_received)
		handle_message_len(signal, &server);
	else
		handle_message(signal, &server);
	kill(server.pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	const pid_t			pid = getpid();
	struct sigaction	sa;

	if (pid < 0)
		ft_error(PID_ERROR_MSG);
	if (write(1, SERVER_PID_MSG, ft_strlen(SERVER_PID_MSG)) == -1
		|| ft_putnbr_fd(pid, 1) == -1
		|| write(1, "\n", 1) == -1)
		ft_error(WRITE_ERROR_MSG);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error(SIGACTION_ERROR_MSG);
	while (1)
		pause();
	return (1);
}
