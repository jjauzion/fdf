/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:11:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/25 15:59:56 by jjauzion         ###   ########.fr       */
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
	double	tmp;

	radian = angle * M_PI / 180.;
	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			tmp = (double)data->tab3[i][j].x; 
			data->tab3[i][j].x = (int)round((double)data->tab3[i][j].x * cos(radian)) + (int)round((double)data->tab3[i][j].z * sin(radian));
			data->tab3[i][j].z = (int)round((double)-tmp * sin(radian)) + (int)round((double)data->tab3[i][j].z * cos(radian));
		}
		i--;
	}
}

void		rotationX(t_data *data, double angle)
{
	int		j;
	int		i;
	double	radian;
	double	tmp;

	radian = angle * M_PI / 180.;
	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			tmp = (double)data->tab3[i][j].y; 
			data->tab3[i][j].y = (int)round((double)data->tab3[i][j].y * cos(radian)) - (int)round((double)data->tab3[i][j].z * sin(radian));
			data->tab3[i][j].z = (int)round(tmp * sin(radian)) + (int)round((double)data->tab3[i][j].z * cos(radian));
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
			data->tab3[i][j].x = (int)((double)data->tab3[i][j].x * factor);
			data->tab3[i][j].z = (int)((double)data->tab3[i][j].z * factor);
		}
		i--;
	}
}

void		zoom(t_data *data, int x, int y, char option)
{
	int	data_width;
	int	data_height;

	(void)x;
	(void)y;
	if (option == 'i')
		scale_factor(data, ZOOM);
	if (option == 'o')
		scale_factor(data, 1. / ZOOM);
data_width = ABS((data->tab3[0][0].x - data->tab3[0][1].x));
data_height = ABS((data->tab3[0][0].z - data->tab3[1][0].z));
printf("00.x = %d ; 01.x = %d\n", data->tab3[0][0].x, data->tab3[0][1].x);
printf("00.z = %d ; 01.z = %d\n", data->tab3[0][0].z, data->tab3[1][0].z);
printf("w = %d ; h = %d\n", data_width, data_height);
}
