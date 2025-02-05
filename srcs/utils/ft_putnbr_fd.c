/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:00:57 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/05 05:03:20 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putull_fd(size_t nb, int fd)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_putull_fd(nb / 10, fd);
	if (write(fd, &"0123456789"[nb % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr_fd(int nb, int fd)
{
	int		is_neg;
	int		len;

	is_neg = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		is_neg = 1;
	}
	len = (ft_putull_fd((size_t) nb, fd));
	if (len == -1)
		return (-1);
	return (len + is_neg);
}
