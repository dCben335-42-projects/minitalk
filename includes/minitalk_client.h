/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:36:00 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/05 06:45:47 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <signal.h>
# include "minitalk_utils.h"

# define CLIENT_USAGE_MSG \
	"Usage: ./client [server_pid] [message]"

# define EMPTY_MESSAGE_MSG \
	 "Error: the message is empty"

# define INVALID_PID_FORMAT_MSG \
	"Error: the pid passed is not a number greater than 0"

# define WRONG_PID_MSG \
	"Error: The pid passed does not match any process"

# define SUCCESS_RECEIVED_MSG \
	"Success: the message was well received"

#endif
