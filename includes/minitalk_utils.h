/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:31:06 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/11 18:27:07 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

# include <unistd.h>
# include <sys/types.h>

typedef enum e_bool
{
	false = 0,
	true = 1,
}	t_bool;

size_t	ft_strlen(const char *s);
int		ft_putendl_fd(const char *s, int fd);
int		ft_mini_atoi(const char *str);
int		ft_putnbr_fd(int nb, int fd);
void	ft_error(const char *msg);
void	*ft_memset(void *b, int c, size_t len);

#endif