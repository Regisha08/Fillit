/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_add_fig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:35:04 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/15 23:50:27 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*add_fig_to_area(char *fig, char *area, int tmp_j, int *arr)
{
	int i;
	int j;
	int width_a;
	
	i = 0;
	j = 0;
	width_a = width_area(area);
	while (i < 4)
	{
		if (arr[0] != 0)
			j = (tmp_j + (((arr[i]) / 5) * width_a) + ((arr[i]) % 5)) - arr[0];
		else
			j = tmp_j + (((arr[i]) / 5) * width_a) + ((arr[i]) % 5);
		area[j] = fig[arr[i]];
		i++;
	}
	printf("area with figure = \n%s", area);
	//check_add_fig(area, fig);
	return (area);
}

char		*check_add_fig(char *area, char *fig, int *arr)
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
		while (area[j] != '.' && check_c == 0 && area[j] != '\0')	
			j++;
		if (area[j] == '.' && check_c == 0) 
			tmp_j = j;
		if (arr[0] != 0)
			j = (tmp_j + (((arr[i]) / 5) * width_a) + ((arr[i]) % 5)) - arr[0];
		else
			j = tmp_j + (((arr[i]) / 5) * width_a) + ((arr[i]) % 5);
		if (area[j] == '.')
		{
			check_c++;
			i++;
		}
		else if ((area[j] != '.' || area[j] != '\n') && check_c != 0)
		{
			i = 0;
			check_c = 0;
			tmp_j++;
			j = tmp_j;
		}
		else
			i++;
		if (area[j] == '\0' && check_c != 4)
			return (area);
	}
	return (add_fig_to_area(fig, area, tmp_j, arr));
}