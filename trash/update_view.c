/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:57:30 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 14:50:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_view(int key, void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (key == 78)
		data->height_factor--;
	if (key == 69)
		data->height_factor++;
	proj_iso(data);
	mlx_clear_window(data->mlx, data->win);
	trace_grid(data);
}
