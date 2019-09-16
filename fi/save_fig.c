/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:34 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/15 20:44:15 by aponomar         ###   ########.fr       */
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


// t_fig		*save_fig(char *fig, int s_num)
// {
// 	t_fig		*new;

// 	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
// 		return (NULL);
// 	new->sn = s_num;
// 	printf("serial number in linked list = \n%d\n", new->sn);
// 	new->fig_save = ft_strnew(20);
// 	new->fig_save = ft_strcpy(new->fig_save, fig);
// 	new->next = NULL;

// 	printf("string in linked list = \n%s", new->fig_save);

// 	return (new);
// }