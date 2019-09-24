/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 05:32:25 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/22 19:12:10 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char		*init_area(int sq_side)
{
	char	*area;
	int		i;

	i = 0;
	area = (char *)malloc(sizeof(char) * ((sq_side + 1) * sq_side + 1));
	while (i < (sq_side + 1) * sq_side)
	{
		if (i % (sq_side + 1) == sq_side)
			area[i] = '\n';
		else
			area[i] = '.';
		i++;
	}
	area[(sq_side + 1) * sq_side] = '\0';
	return (area);
}

int			min_sq_side(int num_elems)
{
	int		lo;
	int		hi;
	int		k;

	lo = 1;
	hi = num_elems;
	k = (lo + hi) / 2;
	if (num_elems == 0)
		return (0);
	while (num_elems > k * k || num_elems <= (k - 1) * (k - 1))
	{
		if (num_elems > k * k)
			lo = k + 1;
		if (num_elems <= (k - 1) * (k - 1))
			hi = k - 1;
		k = (lo + hi) / 2;
	}
	return (k);
}
