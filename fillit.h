/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 04:39:46 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/22 18:55:59 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct		s_fig
{
	int				sn;
	struct s_fig	*next;
	struct s_fig	*prev;
	int				*xind;
	int				*yind;
}					t_fig;

int					fillit(int fd);
t_fig				*read_figs(int fd);
t_fig				*save_fig(char *txt, int sn);
int					count_list(t_fig *head);
void				print_list(t_fig *head);
int					measure_shift_fig_side(int *xind);
int					shift_validate(int hash_count, int *xind, int *yind);
int					fig_txt_to_inds(char *txt, int **xind, int **yind);
void				add_fig(char *area, int sq_side, t_fig *fig, int coord);
void				remove_fig(char *area, int sq_side, t_fig *fig, int coord);
int					can_add_figure(char *area, int sq_side, t_fig *fig,
					int coord);
int					add_the_next_figure_in_list(char *area, int sq_side,
					t_fig *fig_list);
int					min_sq_side(int num_figs);
char				*init_area(int sq_side);
void				dell_fig_list(t_fig *head);
int					prevalidate(char *txt);
t_fig				*fig_to_list(t_fig **head, char *buff);

#endif
