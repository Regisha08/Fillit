/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_save_fig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 05:31:15 by rnureeva          #+#    #+#             */
/*   Updated: 2019/09/22 19:11:46 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int				measure_shift_fig_side(int *xind)
{
	int mn;
	int mx;
	int i;

	i = 0;
	mn = 5;
	mx = 0;
	while (i < 4)
	{
		if (xind[i] < mn)
			mn = xind[i];
		if (xind[i] > mx)
			mx = xind[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		xind[i] = xind[i] - mn;
		i++;
	}
	return (mx - mn + 1);
}

int				shift_validate(int hash_count, int *xind, int *yind)
{
	int width;
	int height;

	width = measure_shift_fig_side(xind);
	height = measure_shift_fig_side(yind);
	if (hash_count != 4)
		return (0);
	if (width * height != 6 && (width * height != 4))
		return (0);
	if (width == 3 && height == 2 && xind[0] == 0 && xind[1] == 2)
		return (0);
	if (width == 2 && height == 3 && yind[1] == 0 && yind[2] == 2)
		return (0);
	return (1);
}

int				fig_txt_to_inds(char *txt, int **xind, int **yind)
{
	int i;
	int hash_ctr;

	*xind = (int*)malloc(4 * sizeof(int));
	*yind = (int*)malloc(4 * sizeof(int));
	hash_ctr = 0;
	i = 0;
	while (i < 20)
	{
		if (txt[i] == '#')
		{
			(*xind)[hash_ctr] = i % 5;
			(*yind)[hash_ctr++] = i / 5;
		}
		if (hash_ctr > 4)
			return (0);
		i++;
	}
	return (hash_ctr);
}

int				prevalidate(char *txt)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (txt[i] != '\n')
				return (0);
		}
		else if (txt[i] != '.' && txt[i] != '#')
			return (0);
		i++;
	}
	return (1);
}
