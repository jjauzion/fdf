/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:43:08 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/22 20:43:54 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		proj_iso(t_data *data)
{
	int j;
	int	i;
	double	x;
	double	z;

	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			x = data->tab3[i][j].x + data->x_offset;
			z = data->tab3[i][j].z + data->z_offset;
			data->tab2[i][j].x = x - z;
			data->tab2[i][j].z = (x + z) / 2.;
			data->tab2[i][j].z -= (double)data->tab3[i][j].y * (double)data->height_factor;
			data->tab2[i][j].height = data->tab3[i][j].y;
		}
		i--;
	}
}
