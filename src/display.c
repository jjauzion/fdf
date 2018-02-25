/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:40:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/25 11:30:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_window(t_data *data, int width, int height)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fdf");
}

void		display(t_data *data, int width, int height)
{
	init_window(data, width, height);
	print2screen(data, 54, 0, 0);
	mlx_key_hook(data->win, key_hook, (void*)data);
	mlx_mouse_hook(data->win, mouse_hook, (void*)data);
	mlx_loop(data->mlx);
}
