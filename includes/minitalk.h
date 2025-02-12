/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:25:07 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/12 15:25:34 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
	"Error: sigaction system call failed"

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

# define CLIENT_USAGE_MSG \
	"Usage: ./client [server_pid] [message]"

# define EMPTY_MESSAGE_MSG \
	"Error: The message is empty"

# define INVALID_PID_FORMAT_MSG \
	"Error: The pid passed is not a positive integ"

# define WRONG_PID_MSG \
	"Error: The pid passed does not match any process"

# define NO_RESPONSE_MSG \
	"Error: The server did not respond, Maybe it is not running anymore"

# define SUCCESS_RECEIVED_MSG \
	"Success: The message was well received"

# define TIMEOUT_US 1000000
# define TIMEOUT_STEPS 10000

#endif