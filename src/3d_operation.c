/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:11:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 20:14:43 by jjauzion         ###   ########.fr       */
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
printf("AV y = %d\n", data->tab3[i][j].y);
printf("AV z = %d\n", data->tab3[i][j].z);
			printf("cos(%.30f) = %.30f\n", radian, cos(radian));
			printf("sin(%.30f) = %.30f\n", radian, sin(radian));
			tmp = (double)data->tab3[i][j].y; 
			data->tab3[i][j].y = (int)round((double)data->tab3[i][j].y * cos(radian)) - (int)round((double)data->tab3[i][j].z * sin(radian));
			data->tab3[i][j].z = (int)round(tmp * sin(radian)) + (int)round((double)data->tab3[i][j].z * cos(radian));
printf("y = %d\n", data->tab3[i][j].y);
printf("z = %d\n", data->tab3[i][j].z);
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
