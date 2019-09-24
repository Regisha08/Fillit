/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 04:39:54 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/22 19:12:02 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			can_add_figure(char *area, int sq_side, t_fig *fig, int coord)
{
	int		x0;
	int		y0;
	int		x;
	int		y;
	int		i;

	x0 = coord % (sq_side + 1);
	y0 = coord / (sq_side + 1);
	i = 0;
	while (i < 4)
	{
		x = x0 + fig->xind[i];
		y = y0 + fig->yind[i];
		if (x >= sq_side || y >= sq_side)
			return (0);
		if (area[y * (1 + sq_side) + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

int			fillit(int fd)
{
	t_fig	*fig_list;
	int		sq_side;
	char	*area;

	fig_list = read_figs(fd);
	if (fig_list == NULL)
		return (0);
	sq_side = min_sq_side(4 * count_list(fig_list));
	area = init_area(sq_side);
	while (add_the_next_figure_in_list(area, sq_side, fig_list) == 0)
	{
		sq_side++;
		free(area);
		area = init_area(sq_side);
	}
	ft_putstr(area);
	free(area);
	dell_fig_list(fig_list);
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (fillit(fd) == 0)
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
