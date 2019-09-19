/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_add_fig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:35:04 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/19 00:12:36 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*add_fig_to_area(char *area, t_fig *get_fig)
{
	get_fig->i = 0;
	get_fig->j = 0;
	while (get_fig->i < 4)
	{
		if (get_fig->arr[0] != 0)
			get_fig->j = (get_fig->tmp_j + (((get_fig->arr[get_fig->i]) / 5) * \
			width_area(area)) + \
			((get_fig->arr[get_fig->i]) % 5)) - get_fig->arr[0];
		else
			get_fig->j = get_fig->tmp_j + (((get_fig->arr[get_fig->i]) / 5) * \
			width_area(area)) + \
			((get_fig->arr[get_fig->i]) % 5);
		area[get_fig->j] = get_fig->fig_save[get_fig->arr[get_fig->i]];
		get_fig->i++;
	}
	printf("area with figure = \n%s\t", area);
	return (area);
}

void		pre_check_add(char *area, t_fig *get_fig)
{
	while (area[get_fig->j] != '.' && get_fig->ch_c == 0 && area[get_fig->j])
		get_fig->j++;
	if (area[get_fig->j] == '.' && get_fig->ch_c == 0 && get_fig->del == 0)
		get_fig->tmp_j = get_fig->j;
	if (get_fig->arr[0] != 0)
		get_fig->j = (get_fig->tmp_j + (((get_fig->arr[get_fig->i]) / 5) * \
		width_area(area)) + ((get_fig->arr[get_fig->i]) % 5)) - get_fig->arr[0];
	else
		get_fig->j = get_fig->tmp_j + (((get_fig->arr[get_fig->i]) / 5) * \
		width_area(area)) + ((get_fig->arr[get_fig->i]) % 5);
	if (area[get_fig->j] == '.')
	{
		get_fig->ch_c++;
		get_fig->i++;
	}
	else if ((area[get_fig->j] != '.' || area[get_fig->j] != '\n') \
	&& get_fig->ch_c != 0)
	{
		get_fig->i = 0;
		get_fig->ch_c = 0;
		get_fig->tmp_j++;
		get_fig->j = get_fig->tmp_j;
	}
	else
		get_fig->i++;
}

char		*check_add_fig(char *area, t_fig *get_fig)
{
	get_fig->i = 0;
	get_fig->j = 0;
	if (get_fig->del == 0)
		get_fig->tmp_j = 0;
	get_fig->ch_c = 0;
	while (area[get_fig->j] != '\0' && get_fig->ch_c != 4)
	{
		pre_check_add(area, get_fig);
		
		if (area[get_fig->j] == '\0' && get_fig->ch_c != 4)
		{
			get_fig->inc = 0;
			// get_fig->tmp_j = 0;
			printf("\n------------\nHeDocTaTo4Ho MeCTa!!!!\n------------\n");
			printf("He BJle3aeT qpurypa: \n%s\n!!!!", get_fig->fig_save);
			return (area);
		}
		else if (get_fig->ch_c == 4)
		{
			get_fig->inc = 1;
			return (add_fig_to_area(area, get_fig));
		}
	}
	return (add_fig_to_area(area, get_fig));
}
