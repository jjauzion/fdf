/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:15:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/22 11:48:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		keyhandler(t_data *data, int key)
{
	if (key == 53)
	{
		free_tab3d(&(data->tab3), data->imax);
		free_tab2d(&(data->tab2), data->imax);
		exit(EXIT_SUCCESS);
	}
	if (key == 78 || key == 27)
		data->height_factor--;
	if (key == 69 || key == 24)
		data->height_factor++;
	if (key == 123)
		translation(data, -DEF_SHIFT, 0);
	if (key == 124)
		translation(data, DEF_SHIFT, 0);
	if (key == 125)
		translation(data, 0, DEF_SHIFT);
	if (key == 126)
		translation(data, 0, -DEF_SHIFT);
	if (key == 0)
		rotationX(data, ROT_ANGLE);
	if (key == 2)
		rotationX(data, -ROT_ANGLE);
	if (key == 1)
		rotationY(data, ROT_ANGLE);
	if (key == 13)
		rotationY(data, -ROT_ANGLE);
	if (key == 15)
		rotationY(data, 90);
}

void		print2screen(void *param, int key)
{
	t_data	*data;

	data = (t_data*)param;
	keyhandler(data, key);
	proj_iso(data);
	mlx_clear_window(data->mlx, data->win);
	trace_grid(data);
}
