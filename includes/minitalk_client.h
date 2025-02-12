/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:36:00 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/12 14:19:33 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <signal.h>
# include "minitalk_utils.h"

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
