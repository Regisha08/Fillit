/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_fig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 05:33:10 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/22 19:12:06 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void		dell_fig_list(t_fig *head)
{
	t_fig *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->xind);
		free(tmp->yind);
		free(tmp);
	}
}
