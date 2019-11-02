/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:40:44 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/24 11:37:44 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	if (!*str)
		return (0);
	while (*str == ' ' || *str == '\v'
			|| *str == '\t' || *str == '\0'
			|| *str == '\r' || *str == '\n'
			|| *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + (*str - 48);
		str++;
	}
	return (nbr * sign);
}
