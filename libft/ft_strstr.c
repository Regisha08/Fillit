/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:12:06 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/22 18:12:45 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *a;
	char *b;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		a = (char*)haystack;
		b = (char*)needle;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
