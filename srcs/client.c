/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:37:04 by bcabocel          #+#    #+#             */
/*   Updated: 2025/01/30 14:43:10 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <time.h>
#include <stdio.h>

void	send_int(int pid, unsigned int value)
{
	int	bit;

	bit = 31;
	while (bit >= 0)
	{
		if (value >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(50000);
	}
}

void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit--;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	send_int(pid, (unsigned int)ft_strlen(message));
	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;
	
	if (argc != 3)
	{
		ft_putendl_fd(CLIENT_USAGE_MSG, 2);
		return (1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putendl_fd("Error: Empty message", 2);
		return (1);
	}
	pid = ft_atoi_base(argv[1], "0123456789");
	if (pid <= 0)
	{
		ft_putendl_fd("Error: Invalid PID", 2);
		return (1);
	}
	send_message(pid, argv[2]);
	return (0);
}


