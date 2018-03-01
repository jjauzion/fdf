/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:51:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/01 15:19:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	interpolate(t_data *data, int height)
{
	int		tsv[2][3];
	int		i;
	int		j;
	double	a;
	int		b;

	i = 1;
	while (++i < data->color[0][0] && height > data->color[0][i])
	{
	}
	ft_rgb2tsv(data->color[1][i - 1], &tsv[0][0], &tsv[0][1], &tsv[0][2]);
	ft_rgb2tsv(data->color[1][i], &tsv[1][0], &tsv[1][1], &tsv[1][2]);
	j = -1;
	while (++j < 3)
	{
		if (data->color[0][i - 1] != data->color[0][i])
			a = (double)(tsv[0][j] - tsv[1][j]) /
				(double)(data->color[0][i - 1] - data->color[0][i]);
		else
			a = 0;
		b = tsv[0][j] - (int)(a * (double)data->color[0][i - 1]);
		tsv[0][j] = (int)((double)height * a) + b;
	}
	return (ft_tsv2rgb(tsv[0][0], tsv[0][1], tsv[0][2]));
}

static int	get_color(t_data *data, int height)
{
	if (data->color[0][0] < 1)
		return (0xFFFFFF);
	if (height < data->color[0][1])
		return (data->color[1][1]);
	else if (height >= data->color[0][data->color[0][0]])
		return (data->color[1][data->color[0][0]]);
	else
		return (interpolate(data, height));
}

void		pixel_put(t_data *data, t_point2d *p, int height, char option)
{
	int	color;

	color = (option == 'c') ? get_color(data, height) : 0xFFFFFF;
	mlx_pixel_put(data->mlx, data->win, p->x, p->z, color);
}
