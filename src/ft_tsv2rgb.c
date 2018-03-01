/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tsv2rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:25:00 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/01 16:01:24 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	rgb_mask(double r, double g, double b, double m)
{
	int	rgb;
	int	ri;
	int	gi;
	int	bi;

	ri = (int)((r + m) * 255.);
	gi = (int)((g + m) * 255.);
	bi = (int)((b + m) * 255.);
	rgb = 0;
	rgb = (ri << 16);
	rgb = (gi << 8) | rgb;
	rgb = bi | rgb;
	return (rgb);
}

static int	check_input(int t, int s, int v)
{
	t = t % 360;
	if (s < 0 || s > 100)
		return (-1);
	if (v < 0 || v > 100)
		return (-1);
	return (t);
}

int			ft_tsv2rgb(int t, int s, int v)
{
	int		rgb;
	double	c;
	double	x;
	double	m;

	if ((t = check_input(t, s, v)) < 0)
		return (-1);
	c = (double)v / 100. * (double)s / 100.;
	x = c * (1 - fabs(fmod((double)t / 60., 2.) - 1));
	m = (double)v / 100. - c;
	rgb = -1;
	if (t < 60)
		rgb = rgb_mask(c, x, 0, m);
	else if (t < 120)
		rgb = rgb_mask(x, c, 0, m);
	else if (t < 180)
		rgb = rgb_mask(0, c, x, m);
	else if (t < 240)
		rgb = rgb_mask(0, x, c, m);
	else if (t < 300)
		rgb = rgb_mask(x, 0, c, m);
	else if (t < 360)
		rgb = rgb_mask(c, 0, x, m);
	return (rgb);
}
