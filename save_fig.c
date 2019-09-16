/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:34 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/15 16:54:43 by rnureeva         ###   ########.fr       */
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

void reverse(t_fig** head_ref) 
{ 
    t_fig *prev = NULL; 
    t_fig *current = *head_ref; 
    t_fig *next = NULL;

    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
	*head_ref = prev;
} 