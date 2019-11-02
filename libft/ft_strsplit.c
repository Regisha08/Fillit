/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:02:42 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/24 12:25:51 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cw(char const *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static	char	**ft_memoryforwords(char const *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	if ((res = (char **)malloc(sizeof(char*) * (ft_cw(str, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if ((res[j++] = (char *)malloc(sizeof(char) * letters + 1)) == NULL)
				return (NULL);
	}
	res[j] = 0;
	return (res);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		str1;
	int		size;

	if (str == NULL)
		return (NULL);
	size = ft_cw(str, c);
	res = ft_memoryforwords(str, c);
	if (res == NULL)
		return (NULL);
	i = 0;
	str1 = 0;
	while (str1 < size)
	{
		while (str[i] == c && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i] != '\0')
			res[str1][j++] = str[i++];
		res[str1][j] = '\0';
		str1++;
	}
	return (res);
}
