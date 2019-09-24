/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:10:45 by rnureeva          #+#    #+#             */
/*   Updated: 2019/09/22 19:10:36 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int				count_list(t_fig *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void			print_list(t_fig *head)
{
	int i;

	while (head != NULL)
	{
		i = 0;
		while (i < 4)
			i++;
		head = head->next;
	}
}

t_fig			*save_fig(char *txt, int sn)
{
	int			*xind;
	int			*yind;
	int			hash_ctr;
	t_fig		*tmp;

	if (prevalidate(txt) == 0)
		return (NULL);
	if ((hash_ctr = fig_txt_to_inds(txt, &xind, &yind)) == 0)
		return (NULL);
	if (shift_validate(hash_ctr, xind, yind) == 0)
		return (NULL);
	tmp = (t_fig *)malloc(sizeof(t_fig));
	tmp->sn = sn;
	tmp->xind = xind;
	tmp->yind = yind;
	tmp->next = NULL;
	return (tmp);
}

t_fig			*fig_to_list(t_fig **head, char *buff)
{
	int			fig_ctr;
	t_fig		*curr_fig;

	fig_ctr = 1;
	curr_fig = *head;
	if (curr_fig == NULL)
	{
		if ((curr_fig = save_fig(buff, 0)) == NULL)
			return (NULL);
		*head = curr_fig;
	}
	else
	{
		while (curr_fig->next)
		{
			curr_fig = curr_fig->next;
			fig_ctr++;
		}
		if ((curr_fig->next = save_fig(buff, fig_ctr)) == NULL)
			return (NULL);
	}
	return (curr_fig);
}

t_fig			*read_figs(int fd)
{
	t_fig		*head;
	int			res;
	char		buff[21];

	head = NULL;
	while ((res = read(fd, buff, 20)) >= 0)
	{
		if (res < 19)
			return (NULL);
		if ((fig_to_list(&head, buff)) == NULL)
			return (NULL);
		if (read(fd, buff, 1) == 0)
			break ;
	}
	if (res == -1)
		return (NULL);
	return (head);
}
