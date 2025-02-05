/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:42:56 by bcabocel          #+#    #+#             */
/*   Updated: 2025/02/05 05:02:26 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"
#include <stdlib.h>

void	ft_error(const char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}
