/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:51:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/22 20:41:41 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_color(t_data *data, int height)
{
	int		t;
	double	a;
	int		b;
	int		seuil1;
	int		seuil2;
	int		color;

	(void)data;
	seuil1 = 1;
	seuil2 = 20;
	if (height < seuil1)
		color = 0x1962E1;
	else if (height < seuil2)
	{
		a = (120 - 34) / (seuil1 - seuil2);
		b = 120 - (int)(a * (double)seuil1);
		t = height * a + b;
		color = ft_tsv2rgb(t, 100, 60);
	}
	else if (height >= seuil2 && height < 80)
		color = ft_tsv2rgb(34, 100, 60);
	else
		color = 0xFFFFFF;
	return (color);
}

void		pixel_put(t_data *data, t_point2d *p, char option)
{
	int	color;
	
	(void)option;
	color = get_color(data, p->height);
	mlx_pixel_put(data->mlx, data->win, p->x, p->z, color);
}
