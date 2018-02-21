/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center2window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:52:28 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 19:30:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_scale(t_point2d **tab, int j_max, int i_max, double *factor)
{
	double	data_width;
	double	data_height;
	double	tmp;

	data_width = tab[0][j_max].x - tab[i_max][0].x;
	data_height = tab[i_max][j_max].z - tab[0][0].z;
	*factor = (double)MAX_WIDTH / data_width;
	tmp = (double)MAX_HEIGHT / data_height;
	if (tmp < *factor)
		*factor = tmp;
	if (*factor < 1.)
		return (1);
	else
		return (0);
}

void		center2window(t_point2d **tab, int j_max, int i_max, int *win_width, int *win_height)
{
	int		min;
	int		max;
	int		x_offset;
	int		z_offset;
	double	factor;

	if (check_scale(tab, j_max, i_max, &factor))
		scale_factor(tab, j_max, i_max, factor);
	min = tab[i_max][0].x;
	max = tab[0][j_max].x;
	*win_width = max - min + 2 * WIN_MARGIN;
	x_offset = *win_width / 2 - (max + min) / 2;
	min = tab[0][0].z;
	max = tab[i_max][j_max].z;
	*win_height = max - min + 2 * WIN_MARGIN;
	z_offset = *win_height / 2 - (max + min) / 2;
	translation(tab, j_max, i_max, x_offset, z_offset);
}
