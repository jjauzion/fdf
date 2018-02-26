/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_hor_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:46:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/26 10:35:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	horizontal_RH_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->x < line.p2->x)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height), option);
		line.p1->x += 1;
	}
}

void	horizontal_LH_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->x > line.p2->x)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height), option);
		line.p1->x -= 1;
	}
}

void	vertical_UP_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->z < line.p2->z)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height), option);
		line.p1->z += 1;
	}
}

void	vertical_DW_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->z > line.p2->z)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height), option);
		line.p1->z -= 1;
	}
}
