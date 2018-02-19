/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_sys_change.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:52:26 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 19:28:54 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		translation(t_point2d **tab, int x_max, int z_max, int x_off, int z_off)
{
	int	x;

	while (z_max >= 0)
	{
		x = -1;
		while (++x <= x_max)
		{
			tab[z_max][x].x += (double)x_off;
			tab[z_max][x].z += (double)z_off;
		}
		z_max--;
	}
}

void		scale_factor(t_point2d **tab, int x_max, int z_max, double factor)
{
	int	x;

	while (z_max >= 0)
	{
		x = -1;
		while (++x <= x_max)
		{
			tab[z_max][x].x = tab[z_max][x].x * factor;
			tab[z_max][x].z = tab[z_max][x].z * factor;
		}
		z_max--;
	}
}
