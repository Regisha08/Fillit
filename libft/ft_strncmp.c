/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:35:24 by rnureeva          #+#    #+#             */
/*   Updated: 2019/04/30 22:35:28 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
