/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:37:48 by bcabocel          #+#    #+#             */
/*   Updated: 2025/01/30 09:53:02 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

int	ft_putendl_fd(const char *s, int fd)
{
	int ret;
	
	ret = write(fd, s, ft_strlen(s));
	if (ret == -1)
		return (-1);
	if (write(fd, "\n", 1) == -1)
		return (-1);
	return (ret + 1);
}
