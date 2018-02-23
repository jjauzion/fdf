/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb2tsv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:58:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/23 14:27:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_input(int rgb, int *t, int *s, int *v)
{
	if (!t || !s || !v)
		return (1);
	if (rgb < 0 || rgb > 0xFFFFFF)
		return (1);
	return (0);
}

int			ft_rgb2tsv(int rgb, int *t, int *s, int *v)
{
	int	*color;
	int	min;
	int	max;

	if (check_input(rgb, t, s, v))
		return (1);
	if (!(color = (int *)malloc(sizeof(int) * 3)))
		return (1);
	color[0] = (rgb & 0xFF0000) >> 16;
	color[1] = (rgb & 0xFF00) >> 8;
	color[2] = rgb & 0xFF;
	max = ft_tab_max(color, 3);
	min = ft_tab_min(color, 3);
	if (max == min)
		*t = 0;
	else if (max == color[0])
		*t = (60 * (color[1] - color[2]) / (max - min) + 360) % 360;
	else if (max == color[1])
		*t = 60 * (color[2] - color[0]) / (max - min) + 120;
	else
		*t = 60 * (color[0] - color[1]) / (max - min) + 240;
	*s = (max == 0) ? 0 : 100 - (int)(100. * (double)min / (double)max);
	*v = (int)(100. * ((double)max / 255.));
	free(color);
	return (0);
}
