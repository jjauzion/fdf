/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:03:36 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/25 19:16:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_param(t_data *data)
{
	data->height_factor = 1;
	data->translation[0] = 0;
	data->translation[1] = 0;
	data->zoom = data->init_zoom;
	data->rotation[0] = 0;
	data->rotation[1] = 0;
	data->rotation[2] = 0;
	data->option = 0;
}
