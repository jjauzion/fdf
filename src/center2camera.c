/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center2camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:43:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 18:46:26 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			check_scale(t_point2d **tab, int j_max, int i_max,
		double *factor)
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

static t_point2d	**proj_corner(t_data *data)
{
	t_point3d	**corner3;
	t_point2d	**corner2;
	t_data		tmp;

	if (!(corner3 = malloc_tab3(1, 1)))
		return (NULL);
	if (!(corner2 = malloc_tab2(1, 1)))
		return (NULL);
	corner3[0][0] = data->tab3[0][0];
	corner3[1][0] = data->tab3[data->imax][0];
	corner3[1][1] = data->tab3[data->imax][data->jmax];
	corner3[0][1] = data->tab3[0][data->jmax];
	tmp.tab3 = corner3;
	tmp.tab2 = corner2;
	tmp.imax = 1;
	tmp.jmax = 1;
	tmp.height_factor = 1;
	proj_iso(&tmp);
	free_tab3d(&corner3, 1);
	return (corner2);
}

static int			set_window(t_data *data, int *win_width, int *win_height)
{
	double		factor;
	t_point2d	**corner2;

	if (!(corner2 = proj_corner(data)))
		return (1);
	if (check_scale(corner2, 1, 1, &factor))
		scale_factor(data, factor);
	free_tab2d(&corner2, 1);
	if (!(corner2 = proj_corner(data)))
		return (1);
	*win_width = corner2[0][1].x - corner2[1][0].x + 2 * WIN_MARGIN;
	*win_height = corner2[1][1].z - corner2[0][0].z + 2 * WIN_MARGIN;
	free_tab2d(&corner2, 1);
	return (0);
}

void				center2camera(t_data *data, int *win_width, int *win_height)
{
	int			centerofWindow_x;
	int			centerofWindow_z;
	int			centerofdata_x;
	int			centerofdata_z;

	set_window(data, win_width, win_height);
	centerofdata_x = (data->tab3[0][data->jmax].x + data->tab3[data->imax][0].x) / 2;
	centerofdata_z = (data->tab3[0][data->jmax].z + data->tab3[data->imax][0].z) / 2;
	translation(data, -centerofdata_x, -centerofdata_z);
	centerofWindow_x = (*win_height + *win_width / 2) / 2;
	centerofWindow_z = (*win_height - *win_width / 2) / 2;
	data->x_offset = centerofWindow_x;
	data->z_offset = centerofWindow_z;
}
