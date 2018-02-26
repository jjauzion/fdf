/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:15:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/26 13:27:52 by jjauzion         ###   ########.fr       */
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
	if (key == 78 || key == 34)
		data->height_factor--;
	if (key == 69 || key == 31)
		data->height_factor++;
	if (key == 123)
		data->translation[0] += -DEF_SHIFT;
	if (key == 124)
		data->translation[0] += DEF_SHIFT;
	if (key == 125)
		data->translation[1] += DEF_SHIFT;
	if (key == 126)
		data->translation[1] += -DEF_SHIFT;
	if (key == 37)
		data->rotation[1] += ROT_ANGLE;
	if (key == 4)
		data->rotation[1] += -ROT_ANGLE;
	if (key == 15)
		data->rotation[1] += 90;
	if (key == 8)
		data->option = (data->option == 'c') ? '\0' : 'c';
	if (key == 7)
		data->color = color_scale();
	if (key == 38)
		data->zoom = data->zoom / ZOOM;
	if (key == 40)
		data->zoom = data->zoom * ZOOM;
	if (key == 49)
		init_param(data);
}

static void	mousehandler(t_data *data, int key, int x, int y)
{
	if (key == -1 && y > 0 && x > 0)
		data->zoom = data->zoom * ZOOM;
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
