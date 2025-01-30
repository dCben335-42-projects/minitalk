/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:45:17 by bcabocel          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:59 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isinbase(char *base, char c)
{
	while (*base)
		if (*base++ == c)
			return (1);
	return (0);
}

int	ft_atoi_base(const char *str, char *base)
{
	long	result;
	int		sign;
	size_t	base_len;

	result = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isinbase(base, *str))
	{
		result = result * base_len + (ft_strchr(base, *str) - base);
		str++;
	}
	return (sign * result);
}
