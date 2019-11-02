/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:43:13 by rnureeva          #+#    #+#             */
/*   Updated: 2019/07/23 16:01:19 by rnureeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	unsigned char y;

	y = (unsigned char)c;
	if (y < 128)
		write(1, &y, 1);
	else
		write(1, &y, 3);
}
