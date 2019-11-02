/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:13:27 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/23 15:13:44 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content_size = 0;
		new_list->content = NULL;
	}
	else
	{
		new_list->content_size = content_size;
		new_list->content = malloc(sizeof(content));
		if (new_list->content == NULL)
			return (NULL);
		ft_memcpy((new_list->content), content, content_size);
	}
	new_list->next = NULL;
	return (new_list);
}
