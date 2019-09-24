/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 05:30:17 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/22 19:12:14 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void		add_fig(char *area, int sq_side, t_fig *fig, int coord)
{
	int		x0;
	int		y0;
	int		i;

	x0 = coord % (sq_side + 1);
	y0 = coord / (sq_side + 1);
	i = 0;
	while (i < 4)
	{
		area[(y0 + fig->yind[i]) * (1 + sq_side) + x0 \
		+ fig->xind[i]] = 'A' + fig->sn;
		i++;
	}
}

int			add_the_next_figure_in_list(char *area, int sq_side,
			t_fig *fig_list)
{
	int coord;
	int max_coord;

	coord = 0;
	max_coord = (1 + sq_side) * sq_side;
	if (fig_list == NULL)
		return (1);
	while (coord < max_coord)
	{
		if (can_add_figure(area, sq_side, fig_list, coord) == 1)
		{
			add_fig(area, sq_side, fig_list, coord);
			if (add_the_next_figure_in_list(area, sq_side, fig_list->next) == 1)
				return (1);
			remove_fig(area, sq_side, fig_list, coord);
		}
		coord++;
	}
	return (0);
}
