/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:36:00 by bcabocel          #+#    #+#             */
/*   Updated: 2025/01/30 11:39:13 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define SERVER_USAGE_MSG "Usage: ./server\n"
# define CLIENT_USAGE_MSG "Usage: ./client [server_pid] [message]\n"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

size_t	ft_strlen(const char *s);
int	ft_putendl_fd(const char *s, int fd);

int	ft_atoi_base(const char *str, char *base);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa_base(int n, char *base);
int	ft_putull_base_fd(size_t nb, char *base, size_t base_len, int fd);
int	ft_putnbr_base_fd(int nb, char *base, int fd);

#endif
