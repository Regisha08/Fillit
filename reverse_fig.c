/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:05:25 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/19 18:05:44 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		reverse_fig(t_fig **head_rev)
{
	t_fig	*prev = NULL;
	t_fig	*current = *head_rev;
	t_fig	*next = NULL;

	while (current != NULL) 
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	*head_rev = prev;
}