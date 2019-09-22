/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:42:43 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/21 17:03:16 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct      s_fig
{
    int             sn;
    struct s_fig    *next;
    struct s_fig    *prev;
    int             *xind;
    int             *yind;
}                   t_fig;

int				fillit(int fd);
t_fig*          read_figs(int fd);
t_fig*          save_fig(char* txt, int sn);
int             count_list(t_fig *head);
void            print_list(t_fig* head);
int             measure_shift_fig_side(int *xind);
void            imprint_fig(char* area, int sq_side, t_fig *fig, int coord, char c);
int             can_add_figure(char* area, int sq_side, t_fig *fig, int coord);
int             add_the_next_figure_in_list(char* , int , t_fig*);
int             min_sq_side(int num_figs);
char*           init_area(int sq_side);

#endif
