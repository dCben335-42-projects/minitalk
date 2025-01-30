/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:00:57 by bcabocel          #+#    #+#             */
/*   Updated: 2025/01/30 10:23:55 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr_base_fd(int nb, char *base, int fd)
{
	size_t	base_len;
	int		is_neg;
	int		len;

	base_len = ft_strlen(base);
	is_neg = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		is_neg = 1;
	}
	len = (ft_putull_base_fd((size_t) nb, base, base_len, fd));
	if (len == -1)
		return (-1);
	return (len + is_neg);
}
