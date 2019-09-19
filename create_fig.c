/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:49:37 by aponomar          #+#    #+#             */
/*   Updated: 2019/09/10 16:50:05 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*create_fig(char *line, char *fig)
{
	char		*tmp;

	tmp = (char *)malloc(sizeof(char) * 6);
	tmp = ft_strcpy(tmp, line);
	tmp[4] = '\n';
	fig = ft_strjoin(fig, tmp);

	return (fig);
}