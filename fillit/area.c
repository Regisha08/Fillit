/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:56:04 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/10 16:48:45 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_sqr(int sum_fig)
{
	int t_const;
	int rest_p;
	int sqr_min;

	t_const = 4;
	sqr_min = 2;
	while ((rest_p = (sqr_min * sqr_min) - (sum_fig * t_const)) < 0)
	{
		printf("res_p = %d\n", rest_p);
		sqr_min++;
	}

	printf("points rest = %d\n", rest_p);

	return (sqr_min);
}

char			*create_area(int sum_fig)
{
	char		*area;
	int			size_area;
	int			i;
	int			min_side;
	int			count;

	min_side = min_sqr(sum_fig);
	printf("min side = %d\n", min_side);
	size_area = (min_side * min_side + min_side) + 1;
	printf("size area = %d\n", size_area);
	area = ft_strnew(size_area);
	area[size_area - 1] = '\0';
	i = 0;
	count = 1;
	while (i < (size_area - 1))
	{		
		if (count % (min_side + 1) == 0 && count != 0)
			area[i] = '\n';
		else
			area[i] = '.';
		i++;
		count++;
	}
	printf("string area = \n%s", area);
	
	return (area);
}