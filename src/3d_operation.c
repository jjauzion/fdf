/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:11:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 17:55:55 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		translation(t_data *data, int x_off, int z_off)
{
	int	j;
	int	i;

	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			data->tab3[i][j].x += (double)x_off;
			data->tab3[i][j].z += (double)z_off;
		}
		i--;
	}
}

void		rotationY(t_data *data, double angle)
{
	int		j;
	int		i;
	double	radian;

	radian = angle * M_PI / 180.;
	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			data->tab3[i][j].x = data->tab3[i][j].x * cos(radian) + data->tab3[i][j].z * sin(radian);
			data->tab3[i][j].z = -data->tab3[i][j].x * sin(radian) + data->tab3[i][j].z * cos(radian);
		}
		i--;
	}
}

void		rotationX(t_data *data, double angle)
{
	int		j;
	int		i;
	double	radian;

	radian = angle * M_PI / 180.;
	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			data->tab3[i][j].y = data->tab3[i][j].y * cos(radian) - data->tab3[i][j].z * sin(radian);
			data->tab3[i][j].z = data->tab3[i][j].y * sin(radian) + data->tab3[i][j].z * cos(radian);
		}
		i--;
	}
}

void		scale_factor(t_data *data, double factor)
{
	int	j;
	int	i;

	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			data->tab3[i][j].x = data->tab3[i][j].x * factor;
			data->tab3[i][j].z = data->tab3[i][j].z * factor;
		}
		i--;
	}
}
