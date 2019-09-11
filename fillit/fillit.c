/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:51:10 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/11 15:39:56 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 		list_size(t_fig *new)
{
	t_fig *tmp;
	
	tmp = new;
	while(tmp->next != NULL)
	{
		if (tmp->sn != 5)
		{	
			printf("string in linked list in fillit = \n%s", tmp->fig_save);
			return (tmp->sn);
		}
		tmp = tmp->next;
	}
	return (tmp->sn);
}

char		*get_fig_from_list(t_fig *get_fig, int s_num)
{
	t_fig *tmp;
	
	tmp = get_fig;
	while(tmp->next != NULL)
	{
		if (tmp->sn == s_num)
		{	
			printf("figure from list by area = \n%s", tmp->fig_save);
			return (tmp->fig_save);
		}
		tmp = tmp->next;
	}

	return (tmp->fig_save);
}

int read_fig(char *line,int fd, int s_num)
{
	int 		i;
	int			count;
	char		*fig = "\0";
	t_fig		*head;
	t_fig		*get_fig;
	
	i = 1;
	count = 0;
	get_fig = NULL;
	while ((i = get_next_line(fd, &line)) > 0 && count != 4 && ft_strlen(line) != 0)
	{
		if (ft_strlen(line) > 4 || (ft_strlen(line) < 4 && ft_strlen(line) != 0))
		{
			// printf("figure invalid!!!(read_fig)\n");
			return (0);
		}
		fig = create_fig(line, fig);
		count++;
		printf("string fig = \n%s", fig);
	}
	if (pre_valid_fig(fig) == -1)
		return (-1);
	else if (s_num == 1)
	{
		get_fig = save_fig(get_fig, move_left_fig(fig), s_num);
		head = get_fig;
	}
	else
	{
		get_fig = save_fig(get_fig, move_left_fig(fig), s_num);//chenged
		
		get_fig = get_fig->next;
		// list_size(head);
		// check_add_fig(area, fig);
	}
	printf("i = %d\n", i);
	if (i == 0)
	{
		printf("comeback list figure = \n%s", head->fig_save);
		if (!get_fig)
			printf("here no list\n");
		else
		{
			exit (1);
		}
		
		count = 1;
		fig = get_fig_from_list(get_fig, count);
		check_add_fig(create_area(s_num), fig);
		return (-1);
	}	
	return (1);
}

int				fillit(int fd)
{
	char		*line="\0";
	// char		*fig = "\0";
	int			s_num;
	int res;
	int i =1;

	s_num = 1;
	// fig = (char *)malloc(sizeof(char) * 21);
	// fig[21] = '\0';
	res = 1;

	while((i = read_fig(line,fd, s_num)) != -1)
	{
	// printf("hi!!\n");
		s_num++;
	}
	// if (i == -1)
		// printf("figure invalid!!!(fillit)\n");
	// move_left_fig(fig);
	// printf("moved figure = \n%s", fig);
	// safe_fig(fig, s_num);
	// create_area(s_num);
	// check_add_fig(create_area(s_num), &fig);
	return (s_num);
}

int		main(void)
{
	int fd;
	
	fd = open("valid_fig_5.txt", O_RDONLY);
	if (fd == -1)
	{
		// printf("Error!");
		return (0);
	}
	else
	
	fillit(fd);
	

	return (0);	
}