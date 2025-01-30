/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:40:12 by bcabocel          #+#    #+#             */
/*   Updated: 2025/01/30 14:39:24 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
}

unsigned char *init_message(unsigned int message_len)
{
	unsigned char *message;
	
	message = malloc((message_len + 1) * sizeof(unsigned char));
	if (!message)
	{
		ft_putendl_fd("Error: malloc failed", 2);
		exit(1);
	}
	ft_memset(message, 0, message_len + 1);
	return (message);
}

void	rebuild_message(int signal, unsigned int *message_len, int *char_index, int *bit_index)
{
	static unsigned char *message = NULL;
	
	if (!message)
		message = init_message(*message_len);
	message[*char_index] |= (signal == SIGUSR1);
	if (++(*bit_index) == 8)
	{
		if (++(*char_index) == (int)*message_len)
		{
			ft_putendl_fd((char *)message, 1);
			free(message);
			message = NULL;
			*char_index = -1;
			*message_len = 0;
		}
		*bit_index = 0;
	}
	else
		message[*char_index] <<= 1;
}

void    get_message_len(int signal, unsigned int *message_len, int *char_index, int *bit_index)
{
	*message_len |= (signal == SIGUSR1);
	*bit_index += 1;
	if (*bit_index == 32)
	{
		*bit_index = 0;
		*char_index = 0;
	}
	else
		*message_len <<= 1;
}

void	handle_signal(int signal)
{
	static unsigned int	message_len = 0;
	static int			char_index = -1;
	static int			bit_index = 0;

	if (char_index == -1)
		get_message_len(signal, &message_len, &char_index, &bit_index);
	else 
		rebuild_message(signal, &message_len, &char_index, &bit_index);
}

int main(void)
{
	const int	pid = getpid();
	
	if (pid == -1)
		return (ft_putendl_fd("Error: getpid failed", 2));
	ft_putendl_fd("Server PID: ", 1);
	ft_putnbr_base_fd(pid, "0123456789", 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while (1)
		pause();

	return (1);
}