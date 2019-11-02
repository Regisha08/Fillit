/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:08:14 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/22 18:08:15 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*begin;

	if (!lst)
		return (NULL);
	new = f(lst);
	begin = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			free(new->next);
			return (NULL);
		}
		new = new->next;
	}
	return (begin);
}
