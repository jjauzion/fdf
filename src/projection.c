/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:43:08 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 14:45:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		proj_iso(t_data *data)
{
	int x;
	int	z;

	z = data->imax;
	while (z >= 0)
	{
		x = -1;
		while (++x <= data->jmax)
		{
			data->tab2[z][x].x = (double)(data->tab3[z][x].x - data->tab3[z][x].z);
			data->tab2[z][x].z = (double)(data->tab3[z][x].x + data->tab3[z][x].z) / 2.;
			data->tab2[z][x].z -= (double)data->tab3[z][x].y * (double)data->height_factor;
		}
		z--;
	}
}
/*
void		proj_cav(t_point3d **tab3, t_point2d **tab2, int x_max, int z_max)
{
	int		i;
	int		j;
	double	rad_a;

	rad_a = ALPHA * M_PI / 180.;
	i = -1;
	while (++i <= z_max)
	{
		j = -1;
		while (++j <= x_max)
		{
			tab2[i][j].x = (double)tab3[i][j].x + COEF * cos(rad_a) * (double)tab3[i][j].y;
			tab2[i][j].z = (double)tab3[i][j].z - COEF * sin(rad_a) * (double)tab3[i][j].y;
		}
	}
}*/
