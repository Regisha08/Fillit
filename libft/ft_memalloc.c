/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:47:49 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/23 15:47:56 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (size == 0)
		return (NULL);
	str = malloc(size);
	if (str)
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return ((void *)str);
	}
	return (NULL);
}
