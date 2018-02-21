/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_sys_change.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:52:26 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 12:58:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		translation(t_data *data, int x_off, int z_off)
{
	int	x;
	int	z;

	z = data->imax;
	while (z >= 0)
	{
		x = -1;
		while (++x <= data->jmax)
		{
			data->tab3[z][x].x += (double)x_off;
			data->tab3[z][x].z += (double)z_off;
		}
		z--;
	}
}

void		scale_factor(t_data *data, double factor)
{
	int	x;
	int	z;

	z = data->imax;
	while (z >= 0)
	{
		x = -1;
		while (++x <= data->jmax)
		{
			data->tab3[z][x].x = data->tab3[z][x].x * factor;
			data->tab3[z][x].z = data->tab3[z][x].z * factor;
		}
		z--;
	}
}
