/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:51:10 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/19 22:58:19 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_list(t_fig *list)
{
	t_fig	*tmp = list;
	int		i;

	i = 0;
	printf("\n\n----------------------------------------\n\n");
	while (tmp)
	{
		i = 0;
		printf("[%d]\n%s\n", tmp->sn, tmp->fig_save);
		while (i < 4)
		{
			printf("{%d} ", tmp->arr[i]);
			i++;
		}
		printf("\n");
		printf("tmp =\t%d\n del =\t%d\n inc =\t%d\n",tmp->tmp_j, tmp->del, tmp->inc);
		
		tmp = tmp->next;
	}
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

int read_fig(char *line, t_fig *get_fig, int fd, int s_num)
{
	int 		i;
	int			j;
	int			count;
	char		*fig = "\0";
	t_fig		*head;
	char		*area = "\0";
	
	i = 1;
	// j = 1;
	count = 0;
	while (i != 0)
	{
		while ((i = get_next_line(fd, &line)) > 0 && count != 4 && ft_strlen(line) != 0)
		{
			if (ft_strlen(line) > 4 || (ft_strlen(line) < 4 && ft_strlen(line) != 0))
				return (0);
			fig = create_fig(line, fig);
			count++;	
		}
		if (pre_valid_fig(fig) == -1)
			return (-1);
		
		get_fig = save_fig(get_fig, move_left_fig(fig), s_num);
		if (s_num == 1)
		{
			head = get_fig;
			head->next = get_fig;
		}
		get_fig = get_fig->next;
		get_fig->next = NULL;
		s_num++;
		count = 0;
		fig = "\0";
	}
	get_fig->sum_fig = s_num - 1;
	head->sum_fig = s_num - 1;
	
	print_list(head);

	area = create_area(s_num);
	fig = check_add_fig(area, head);
	get_fig = head->next;
	printf("include head: %d\n", head->inc);
	while (get_fig->next != NULL)
	{
		check_add_fig(fig, get_fig);
		printf("include: %d\n", get_fig->inc);
		get_fig = get_fig->next;
	}
	check_add_fig(fig, get_fig);
	printf("include: %d\n", get_fig->inc);
	
	i = 0;
	j = 1;
	get_fig->sum_fig = head->sum_fig;
	printf("sum_fig in head: %d\n", head->sum_fig);
	printf("sum_fig in get_fig: %d\n", get_fig->sum_fig);
	while (get_fig->sn != 1 || (get_fig->sn == get_fig->sum_fig && get_fig->inc == 1))
	{
		if (get_fig->inc == 0)
			i = get_fig->sn - j;
		else
			i = get_fig->sn + j;
		get_fig = head->next;
		get_fig->sum_fig = head->sum_fig;
		printf("sum_fig in head: %d\n", head->sum_fig);
		printf("sum_fig in get_fig: %d\n", get_fig->sum_fig);
		while (get_fig->sn != i || (get_fig->sn == get_fig->sum_fig && get_fig->inc == 1))
        	get_fig = get_fig->next;
		if (get_fig->inc == 1 || (get_fig->del == 1 && get_fig->tmp_j == 0))
		{
			find_fig_for_del(area, get_fig, i);
		}
		if (get_fig->inc == 0 && get_fig->del == 1)
		{
			if (get_fig->tmp_j != ((int)ft_strlen(area) - 1) || get_fig->inc == 1)
			{
				get_fig->tmp_j++;
				check_add_fig(area, get_fig);
			}
			if (get_fig->tmp_j == ((int)ft_strlen(area) - 1))
				check_add_fig(area, get_fig);
			if ((get_fig->tmp_j == ((int)ft_strlen(area) - 1)) && get_fig->del == 1)
			{
				i--;
				get_fig = head->next;
				while (get_fig->sn != i || (get_fig->sn == get_fig->sum_fig && get_fig->inc == 1))
					get_fig = get_fig->next;
				find_fig_for_del(area, get_fig, i);
				get_fig->tmp_j++;
				check_add_fig(area, get_fig);
			}
			if (get_fig->inc == 1)
			{
				get_fig = get_fig->next;
				get_fig->del = 0;
				check_add_fig(area, get_fig);
				// j++;
			}
			if (get_fig->sn == get_fig->sum_fig && get_fig->inc == 1)
				return (1);
			// else
			// {
			// 	j--;
			// }
		}	
		
		// else if (head->inc == 1 && head->del == 0)
		// {
		// 	head->tmp_j = 0;
		// }
		
		
	}
	

	return (1);
}
	
	// check_add_fig(area, fig);
	
	// if (i == 0)
	// {
	// 	// printf("comeback list figure = \n%s", head->fig_save);
	// 	// if (!get_fig)
	// 		// printf("here no list\n");
	// 	// else
	// 	// {
	// 	// 	exit (1);
	// 	// }
		
	// 	// print_list(head);
	// 	count = 1;
	// 	fig = get_fig_from_list(get_fig, count);
	// 	check_add_fig(create_area(s_num), fig);
	// 	return (-1);
	// }	


int				fillit(int fd)
{
	char		*line = "\0";
	int			s_num;
	int res;
	// int i =1;
	t_fig		*get_fig = NULL;
	s_num = 1;
	
	res = 1;
	read_fig(line, get_fig, fd, s_num);
	
	// while((i = read_fig(line, get_fig, fd, s_num)) != -1)
	// {
	// 	s_num++;
	// }
	// check_add_fig(create_area(s_num), get_fig->fig_save);
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
