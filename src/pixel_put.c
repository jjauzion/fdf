/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:51:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/23 16:50:05 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_color(t_data *data, int height)
{
	double	a;
	int		b;
	int		color;
	int		tsv1[3];
	int		tsv2[3];
	int		i;
	int		j;

	if (data->color[0][0] < 1)
		return (0xFFFFFF);
	if (height < data->color[0][1])
		color = data->color[1][1];
	else if (height >= data->color[0][data->color[0][0]])
		color = data->color[1][data->color[0][0]];
	else
	{
		i = 1;
		while (++i < data->color[0][0] && height > data->color[0][i])
		{
		}
		ft_rgb2tsv(data->color[1][i - 1], &tsv1[0], &tsv1[1], &tsv1[2]);
		ft_rgb2tsv(data->color[1][i], &tsv2[0], &tsv2[1], &tsv2[2]);
		j = -1;
		while (++j < 3)
		{
			if (data->color[0][i - 1] != data->color[0][i])
				a = (double)(tsv1[j] - tsv2[j]) / (double)(data->color[0][i - 1] - data->color[0][i]);
			else
				a = 0;
			b = tsv1[j] - (int)(a * (double)data->color[0][i - 1]);
			tsv1[j] = (int)((double)height * a) + b;
		}
		color = ft_tsv2rgb(tsv1[0], tsv1[1], tsv1[2]);
	}
	return (color);
}

void		pixel_put(t_data *data, t_point2d *p, char option)
{
	int	color;
	
	(void)option;
	color = (option == 'c') ? get_color(data, p->height) : 0xFFFFFF;
	mlx_pixel_put(data->mlx, data->win, p->x, p->z, color);
}
