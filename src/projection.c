/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:43:08 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/26 16:45:49 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	copy_tab3(t_point3d **dest, t_point3d **src, int jmax, int imax)
{
	int	j;

	while (imax >= 0)
	{
		j = jmax;
		while (j >= 0)
		{
			dest[imax][j].x = src[imax][j].x;
			dest[imax][j].y = src[imax][j].y;
			dest[imax][j].z = src[imax][j].z;
			j--;
		}
		imax--;
	}
}

void		proj_iso(t_data *data)
{
	int		j;
	int		i;
	double	x;
	double	z;

	if (data->tab3)
		copy_tab3(data->transtab3, data->tab3, data->jmax, data->imax);
	translation(data, data->transtab3, data->translation[0], data->translation[1]);
	scale_factor(data, data->transtab3, data->zoom);
	rotationX(data, data->transtab3, data->rotation[0]);
	rotationY(data, data->transtab3, data->rotation[1]);
	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			x = data->transtab3[i][j].x + data->x_offset;
			z = data->transtab3[i][j].z + data->z_offset;
			data->tab2[i][j].x = x - z;
			data->tab2[i][j].z = (x + z) / 2.;
			data->tab2[i][j].z -= (double)data->transtab3[i][j].y * (double)data->height_factor * data->zoom;
			data->tab2[i][j].height = data->transtab3[i][j].y;
		}
		i--;
	}
}
