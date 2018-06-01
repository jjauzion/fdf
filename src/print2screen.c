/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:15:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/01 14:33:22 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	keyhandler(t_data *data, int key)
{
	if (key == 53)
	{
		free_tab3d(&(data->tab3), data->imax);
		free_tab2d(&(data->tab2), data->imax);
		exit(EXIT_SUCCESS);
	}
	if (key == 8)
		data->option = (data->option == 'c') ? '\0' : 'c';
	(key == 69 || key == 31) ? data->height_factor++ : 0;
	(key == 78 || key == 34) ? data->height_factor-- : 0;
	data->translation[0] += (key == 123) ? -DEF_SHIFT : 0;
	data->translation[0] += (key == 124) ? DEF_SHIFT : 0;
	data->translation[1] += (key == 125) ? DEF_SHIFT : 0;
	data->translation[1] += (key == 126) ? -DEF_SHIFT : 0;
	data->rotation[1] += (key == 37) ? ROT_ANGLE : 0;
	data->rotation[1] += (key == 4) ? -ROT_ANGLE : 0;
	data->rotation[1] += (key == 15) ? 90 : 0;
	data->color = (key == 7) ? color_scale() : data->color;
	data->zoom = (key == 38) ? data->zoom / ZOOM : data->zoom;
	data->zoom = (key == 40) ? data->zoom * ZOOM : data->zoom;
	(key == 49) ? init_param(data) : 0;
}

static void	mousehandler(t_data *data, int key, int x, int y)
{
	(void)data;
	(void)key;
	(void)x;
	(void)y;
}

void		print2screen(void *param, int key, int x, int y)
{
	t_data	*data;

	data = (t_data*)param;
	keyhandler(data, key);
	mousehandler(data, key, x, y);
	proj_iso(data);
	mlx_clear_window(data->mlx, data->win);
	trace_grid(data, data->option);
}
