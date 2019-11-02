/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:58:18 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/22 17:58:19 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst2;
	unsigned char *src2;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	if (dst >= src)
		while (len--)
			dst2[len] = src2[len];
	else
		while (len--)
		{
			*dst2 = *src2;
			src2++;
			dst2++;
		}
	return (dst);
}
