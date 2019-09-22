/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:53:38 by Nik               #+#    #+#             */
/*   Updated: 2019/09/21 17:02:54 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void			imprint_fig(char* area, int sq_side, t_fig *fig, int coord, char c)
{
	int x0;
	int y0;
	int i;
	
	x0 = coord%(sq_side+1);
	y0 = coord/(sq_side+1);
	i = 0;
	while (i < 4)
	{
		area[(y0+fig->yind[i])*(1+sq_side) + x0+fig->xind[i]] = c;
		i++;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int				can_add_figure(char* area, int sq_side, t_fig *fig, int coord)
{
	int x0;
	int y0;
	int x;
	int y;
	int i;
	
	x0 = coord%(sq_side+1);
	y0 = coord/(sq_side+1);
	i = 0;
	while (i < 4)
	{
		x = x0 + fig->xind[i];
		y = y0 + fig->yind[i];
		if (x>=sq_side || y>=sq_side)
			return (0);
		if (area[y*(1+sq_side) + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int				add_the_next_figure_in_list(char* area, int sq_side, t_fig* fig_list)
{
	int coord;
	int max_coord;

	coord = 0;
	max_coord = (1 + sq_side)*sq_side;
	if (fig_list == NULL)
		return (1);
	while (coord < max_coord)
	{
		if (can_add_figure(area, sq_side, fig_list, coord) == 1)
		{
			imprint_fig(area, sq_side, fig_list, coord, 'A'+fig_list->sn);
			if (add_the_next_figure_in_list(area, sq_side, fig_list->next)==1)
				return 1;
	        imprint_fig(area, sq_side, fig_list, coord, '.'); //remove figure
	    }
        coord++;
    }
    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int         min_sq_side(int num_elems){
    if (num_elems==0) return 0;
    int lo = 1;
    int hi = num_elems;
    int k = (lo+hi)/2;
    while(num_elems>k*k || num_elems<=(k-1)*(k-1)){
        if (num_elems>k*k)
            lo = k+1;
        if (num_elems<=(k-1)*(k-1))
            hi = k-1;
        k = (lo+hi)/2;
    }
    return k;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char*         init_area(int sq_side){
    char* area = (char*)malloc(sizeof(char)*((sq_side+1)*sq_side+1));
    int i;
    i = 0;
    while(i<(sq_side+1)*sq_side){
        if(i%(sq_side+1)==sq_side)
            area[i]='\n';
        else
            area[i]='.';
        i++;
    }
	area[(sq_side+1)*sq_side]='\0';
    return area;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void			dell_fig_list(t_fig *head)
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

int				fillit(int fd)
{
	t_fig *fig_list = read_figs(fd);
    if (fig_list==NULL)
        return(0);

    int sq_side = min_sq_side(4*count_list(fig_list));

    char* area = init_area(sq_side);

    while(add_the_next_figure_in_list(area, sq_side, fig_list)==0){
        sq_side++;
        free(area);
        area = init_area(sq_side);
    }
    ft_putstr(area);
    //ft_putstr("\n");
    dell_fig_list(fig_list);
	return (1);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int		main(int argc, char **argv)
//int		main()
{
	int fd;

	if (argc != 2)
		return(0);

	fd = open(argv[1], O_RDONLY);
	//fd = open("valid_fig_5.txt", O_RDONLY);
	if (fd == -1){
		ft_putstr("error\n");
		return (0);
	}
		

	if (fillit(fd)==0){
		ft_putstr("error\n");
		close(fd);
		return (0);
	}

	return (1);	
}
