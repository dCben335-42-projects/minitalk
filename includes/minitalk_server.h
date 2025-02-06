/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:19:56 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/06 19:03:41 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# define _POSIX_C_SOURCE 200809L

# include "minitalk_utils.h"
# include <signal.h>
# include <stdlib.h>

# define SERVER_PID_MSG \
	"Server pid: "

# define MALLOC_ERROR_MSG \
	"Error: malloc system call failed"

# define WRITE_ERROR_MSG \
	"Error: write system call failed"

# define PID_ERROR_MSG \
	"Error: the pid has not been granted by the system"

# define SIGACTION_ERROR_MSG \
	"Error: sigaction"

# define DIFFERENT_CLIENT_MSG \
	"Error: A signal came from a different client during message processing."

typedef struct s_server
{
	t_bool			is_receiving;
	pid_t			pid;
	t_bool			is_message_len_received;
	unsigned int	message_len;
	unsigned char	*message;
	unsigned int	char_index;
	unsigned int	bit_index;
}	t_server;

#endif