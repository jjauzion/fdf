/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:11:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/01 16:08:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		translation(t_data *data, t_point3d **tab3, int x_off, int z_off)
{
	int	j;
	int	i;

	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			tab3[i][j].x += (double)x_off;
			tab3[i][j].z += (double)z_off;
		}
		i--;
	}
}

void		rotation_y(t_data *data, t_point3d **tab3, double angle)
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
			tmp = (double)tab3[i][j].x;
			tab3[i][j].x = (int)round((double)tab3[i][j].x * cos(radian))
				+ (int)round((double)tab3[i][j].z * sin(radian));
			tab3[i][j].z = (int)round((double)-tmp * sin(radian)) +
				(int)round((double)tab3[i][j].z * cos(radian));
		}
		i--;
	}
}

void		rotation_x(t_data *data, t_point3d **tab3, double angle)
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
			tmp = (double)tab3[i][j].y;
			tab3[i][j].y = (int)round((double)tab3[i][j].y * cos(radian))
				- (int)round((double)tab3[i][j].z * sin(radian));
			tab3[i][j].z = (int)round(tmp * sin(radian)) +
				(int)round((double)tab3[i][j].z * cos(radian));
		}
		i--;
	}
}

void		scale_factor(t_data *data, t_point3d **tab3, double factor)
{
	int	j;
	int	i;

	i = data->imax;
	while (i >= 0)
	{
		j = -1;
		while (++j <= data->jmax)
		{
			tab3[i][j].x = (int)((double)tab3[i][j].x * factor);
			tab3[i][j].z = (int)((double)tab3[i][j].z * factor);
		}
		i--;
	}
}
