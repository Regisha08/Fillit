/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:52:45 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/17 16:17:01 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct      s_fig
{
    int             sn;
    int             tmp_j; // start index at the time of adding the figure to the area
    int             inc; // variable what show included figure (1) or not (0)
    int             del;
    int             ch_c;
    int             i;
    int             j;
    char            *fig_save;
    int             arr[4];
    struct s_fig    *next;
    struct s_fig    *prev;
}                   t_fig;

char                *check_add_fig(char *area, t_fig *get_fig);
char                *convert_to_letter(t_fig *get_fig);
char                *create_area(int sum_fig);
char                *create_fig(char *line, char *fig);
void                find_fig_for_del(char *area, t_fig *get_fig, int i);
int		            get_next_line(const int fd, char **line);
int		            min_sqr(int sum_fig);
char                *move_left_fig(char *fig);
int		            pre_valid_fig(char *fig);
void		        print_list(t_fig *list);
int                 read_fig(char *line, t_fig *get_fig, int fd, int s_num);
void		        reverse_fig(t_fig **head_rev);
t_fig		        *save_fig(t_fig *list, char *fig, int s_num);
int                 valid_fig(char *fig);
int		            width_area(char *area);

#endif