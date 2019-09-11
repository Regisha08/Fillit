/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:52:45 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/10 21:15:39 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct      s_fig
{
    int             sn;
    char            *fig_save;
    struct s_fig    *next;
    struct s_fig    *prev;
}                   t_fig;

char			    *create_area(int sum_fig);
char		        *create_fig(char *line, char *fig);
int                 check_add_fig(char *area, char *fig);
int		            min_sqr(int sum_fig);
int		            get_next_line(const int fd, char **line);
char                *move_left_fig(char *fig);
int                 valid_fig(char *fig);
int		            pre_valid_fig(char *fig);
t_fig		        *save_fig(t_fig *list, char *fig, int s_num);

#endif
