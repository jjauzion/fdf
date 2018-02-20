/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center2camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:43:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/20 20:17:37 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			check_scale(t_point2d **tab, int j_max, int i_max, double *factor)
{
	double	data_width;
	double	data_height;
	double	tmp;

	data_width = tab[0][j_max].x - tab[i_max][0].x;
	data_height = tab[i_max][j_max].z - tab[0][0].z;
	*factor = (double)(MAX_WIDTH - 2 * WIN_MARGIN) / data_width;
	tmp = (double)(MAX_HEIGHT - 2 * WIN_MARGIN) / data_height;
	if (tmp < *factor)
		*factor = tmp;
	if (*factor < 1.)
		return (1);
	else
		return (0);
}

static t_point2d	**proj_corner(t_point3d **tab, int j_max, int i_max)
{
	t_point3d	**corner3;
	t_point2d	**corner2;

	if (!(corner3 = malloc_tab3(1, 1)))
		return (NULL);
	if (!(corner2 = malloc_tab2(1, 1)))
		return (NULL);
	corner3[0][0] = tab[0][0];
	corner3[1][0] = tab[i_max][0];
	corner3[1][1] = tab[i_max][j_max];
	corner3[0][1] = tab[0][j_max];
	proj_iso(corner3, corner2, 1, 1, 1);
	free_tab3d(&corner3, 1);
	return (corner2);
}

static int			set_window(t_point3d **tab, int j_max, int i_max, int *win_width, int *win_height)
{
	double		factor;
	t_point2d	**corner2;

	if (!(corner2 = proj_corner(tab, j_max, i_max)))
		return (1);
	if (check_scale(corner2, 1, 1, &factor))
		scale_factor3d(tab, j_max, i_max, factor);
	free_tab2d(&corner2, 1);
	if (!(corner2 = proj_corner(tab, j_max, i_max)))
		return (1);
	*win_width = corner2[0][1].x - corner2[1][0].x + 2 * WIN_MARGIN;
	*win_height = corner2[1][1].z - corner2[0][0].z + 2 * WIN_MARGIN;
	free_tab2d(&corner2, 1);
	return (0);
}

void				center2camera(t_point3d **tab, int j_max, int i_max, int *win_width, int *win_height)
{
	int			x_offset;
	int			z_offset;
	int			xc_cartesian;
	int			zc_cartesian;

	set_window(tab, j_max, i_max, win_width, win_height);
	xc_cartesian = (*win_height + *win_width / 2) / 2;
	x_offset = xc_cartesian - (tab[0][j_max].x + tab[i_max][0].x) / 2;
	zc_cartesian = (*win_height - *win_width / 2) / 2;
	z_offset = zc_cartesian - (tab[0][j_max].z + tab[i_max][0].z) / 2;
	translation3d(tab, j_max, i_max, x_offset, z_offset);
}
