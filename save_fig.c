/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:34 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/17 16:19:02 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig		*save_fig(t_fig *list, char *fig, int s_num)
{
	t_fig	*tmp = list;
	t_fig	*new = (t_fig *)malloc(sizeof(t_fig));
	new->fig_save = fig;
	
	// printf("string in list = \n%s", new->fig_save = fig);
	new->sn = s_num;
	// printf("serian number figure = %d\n", new->sn = s_num);
	new->fig_save = convert_to_letter(new);
	new->next = NULL;
	new->del = 0;
	new->inc = 0;
	if (!list)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	
	return(list); 
}

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