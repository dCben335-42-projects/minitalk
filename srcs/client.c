/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:37:04 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/05 06:20:58 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>
#include <stdlib.h>

volatile t_bool	g_is_bit_received = false;

static void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		g_is_bit_received = true;
	if (signal == SIGUSR2)
	{
		ft_putendl_fd(SUCCESS_RECEIVED_MSG, 1);
		exit(0);
	}
}

static void	send_bit(int pid, void *value, ssize_t bit)
{
	const unsigned char	*bytes = (const unsigned char *)value;
	const int			byte_index = bit / 8;
	const int			bit_index = bit % 8;
	const int			bit_value = (bytes[byte_index] >> bit_index) & 1;

	if (bit_value)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error(WRONG_PID_MSG);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error(WRONG_PID_MSG);
	}
	while (!g_is_bit_received)
		;
	g_is_bit_received = false;
}

static void	send_message(int pid, char *message)
{
	size_t	message_len;
	ssize_t	bit;

	message_len = ft_strlen(message);
	bit = 32;
	while (--bit >= 0)
		send_bit(pid, (void *)&message_len, bit);
	while (*message)
	{
		bit = 8;
		while (--bit >= 0)
			send_bit(pid, message, bit);
		message++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		ft_error(CLIENT_USAGE_MSG);
	if (!*argv[2])
		ft_error(EMPTY_MESSAGE_MSG);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_error(INVALID_PID_FORMAT_MSG);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	send_message(pid, argv[2]);
	return (0);
}
