/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 05:30:54 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/22 19:10:56 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void		remove_fig(char *area, int sq_side, t_fig *fig, int coord)
{
	int		x0;
	int		y0;
	int		i;

	x0 = coord % (sq_side + 1);
	y0 = coord / (sq_side + 1);
	i = 0;
	while (i < 4)
	{
		area[(y0 + fig->yind[i]) * (1 + sq_side) + x0 + fig->xind[i]] = '.';
		i++;
	}
}
