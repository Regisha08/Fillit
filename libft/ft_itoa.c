/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:54:56 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/30 18:44:58 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num(int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int nbr)
{
	char	*result;
	int		len;
	int		stop;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num(nbr);
	stop = 0;
	if ((result = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	result[len--] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
		stop = 1;
	}
	while (len >= stop)
	{
		result[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (result);
}
