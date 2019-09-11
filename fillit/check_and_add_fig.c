/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:35:04 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/10 16:52:15 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		width_area(char *area)
{
	int i;

	i = 0;
	while (area[i] != '\n')
		i++;
	printf("width area = %d\n", i);
	return (i + 1);
}

int		add_fig_to_area(char *fig, char *area, int tmp_j)
{
	int i;
	int j;
	int width_a;
	
	i = 0;
	j = 0;
	width_a = width_area(area);
	while (area[j] != '\0' && fig[i] != '\0' && j < (int)ft_strlen(area))
	{
		while (fig[i] != '#' && fig[i] != '\0')
			i++;
		j = tmp_j + ((i / 5) * width_a) + (i % 5);
		if (fig[i] == '#' && area[j] == '.')
		{
			area[j] = '#';
			i++;
		}
		if (fig[i] == '#' && area[j] == '.')
		{
			i++;
			area[j] = '#';
		}
	}
	check_add_fig(area, fig);
	printf("area with figure = \n%s", area);
	return (0);
}

int		check_add_fig(char *area, char *fig)
{
	int i;
	int j;
	int check_c;
	int width_a;
	int tmp_j;

	i = 0;
	j = 0;
	tmp_j = 0;
	check_c = 0;
	width_a = width_area(area);
	while (area[j] != '\0' && check_c != 4)
	{
		while (fig[i] != '#')
			i++;
		if (check_c == 0)
			tmp_j = j;
		j = tmp_j + ((i / 5) * width_a) + (i % 5);
		if (fig[i] == '#' && area[j] == '.' && check_c == 0)
		{
			check_c++;
			i++;
		}
		else if (area[j] == '#' && check_c != 0)
		{
			check_c = 0;
			tmp_j++;
			i = 0;
		}
		if (fig[i] == '#' && area[j] == '.')
		{
			i++;
			check_c++;
		}
		else if (area[j] != '.')
			j++;
	}
	printf("check_c = %d\n\n\n", check_c);
	printf("add fig in area = \n%s\n", area);
	return (add_fig_to_area(fig, area, tmp_j));
}