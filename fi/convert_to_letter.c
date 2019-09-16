/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_letter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:51:55 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/15 22:51:26 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char        *convert_to_letter(t_fig *get_fig)
{
    t_fig	*tmp = get_fig;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (tmp->fig_save[i] != '\0')
    {
        if (tmp->fig_save[i] == '#')
        {
            tmp->arr[j] = i; // save index figure element in integer array 
            tmp->fig_save[i] = ((tmp->sn) + 64);
            j++;
        }
        i++;
    }
    // while (tmp->arr[0] != 0)
    // {   
    //     j = 0;
    //     while (j < 4)
    //     {
    //         tmp->arr[j]--;
    //         j++;
    //     }
    // }
    return (tmp->fig_save);
}