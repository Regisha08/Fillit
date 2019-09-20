/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:50:59 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/19 14:38:04 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    delete_fig(char *area, t_fig *get_fig)
{
    int i;

    i = 0;
    while (area[i])
    {
        if (area[i] == (get_fig->sn + 64))
            area[i] = '.';
        i++;
    }
    printf("area minus prelast figure = \n%s", area);
    // get_fig->tmp_j++;
    get_fig->del = 1;
    get_fig->inc = 0;
    printf("in delete_fig:\nname fig: %c\ntmp =\t%d\ndel =\t%d\ninc =\t%d\n", get_fig->sn + 64, get_fig->tmp_j, get_fig->del, get_fig->inc);
    //check_add_fig(area, get_fig);
}

void    find_fig_for_del(char *area, t_fig *get_fig, int i)
{
    // while (get_fig->sn != i)
    //     get_fig = get_fig->next;
    // if (get_fig->inc == 0)
    if (get_fig->sn == i)
        delete_fig(area, get_fig);  
}
