/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:12:04 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/10 16:38:41 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_fig(char *fig)
{
	int i;
	int touch_c;

	i = 0;
	touch_c = 0;
	while (fig[i] != '\0')
	{
		if (fig[i] == '#')
		{
			if (fig[i - 1] == '#' && i != 0 && i != 5 && i != 10 && i != 15)
				touch_c++;
			if (fig[i + 1] == '#' && i != 3 && i != 8 && i != 13 && i != 19)
				touch_c++;
			if (fig[i + 5] == '#' && i < 14)
				touch_c++;
			if (fig[i - 5] == '#' && i < 19 && i > 4)
				touch_c++;
		}
		i++;
	}
	return ((touch_c == 6 || touch_c == 8) ? 0 : -1);	
}

int		pre_valid_fig(char *fig)
{
    int i;
    int count_p;
    int count_sh;

    i = 0;
    count_p = 0;
    count_sh = 0;
    while (fig[i] != '\0')
    {
        if (fig[i] == '.')
            count_p++;
        if (fig[i] == '#')
            count_sh++;
        if (fig[i] != '.' && fig[i] != '#' && fig[i] != '\n' && i != 20)
		{	
			printf("figure invalid!!!(read_fig)\n");
            return (-1);
		}
        i++;
    }
	return (count_p == 12 && count_sh == 4) ? (valid_fig(fig)) : -1;
}