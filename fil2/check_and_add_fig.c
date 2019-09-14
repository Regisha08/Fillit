/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_add_fig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:35:04 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/13 22:05:13 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*add_fig_to_area(char *fig, char *area, int tmp_j)
{
	int i;
	int j;
	int width_a;
	
	i = 0;
	j = 0;
	width_a = width_area(area);
	while (area[j] != '\0' && fig[i] != '\0' && j < (int)ft_strlen(area))
	{
		while (fig[i] == '.' && fig[i] != '\0')
			i++;
		j = tmp_j + ((i / 5) * width_a) + (i % 5);
		if (fig[i] != '.' && fig[i] != '\n' && area[j] == '.')
		{
			area[j] = fig[i];
			i++;
		}
		else
			i++;		
	}
	printf("area with figure = \n%s", area);
	//check_add_fig(area, fig);
	return (area);
}

char		*check_add_fig(char *area, char *fig)
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
		while (fig[i] == '.' || fig[i] == '\n')
			i++;
		if (check_c == 0)
			tmp_j = j;
		j = tmp_j + ((i / 5) * width_a) + (i % 5);
		if (((fig[i] != '.' && fig[i] != '\n') && area[j] == '.' && check_c == 0) || ((fig[i] != '.' && fig[i] != '\n') && area[j] == '.'))
		{
			check_c++;
			i++;
			j++;
		}
		if ((area[j] != '.' || area[j] == '\n') && check_c != 0 && (fig[i] != '.' && fig[i] != '\n'))
		{
			check_c = 0;
			tmp_j++;
			i = 0;
		}
		if (area[j] != '.')
			j++;
		if (area[j] == '\0' && check_c != 4)
		{
			printf("j = %d\n", j);
			printf("not enough free space!!!\n");
			return (area);
		}
	}
	// printf("area before add = \n%s\n", area);
	// printf("check_c = %d\n\n\n", check_c);
	return (add_fig_to_area(fig, area, tmp_j));
}