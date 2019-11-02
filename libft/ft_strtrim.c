/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:08:46 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/23 17:11:26 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*res;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	res = str;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (*s)
	{
		*str = *s;
		str++;
		s++;
	}
	str--;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str--;
	str++;
	*str = '\0';
	return (res);
}
