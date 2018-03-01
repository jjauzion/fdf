/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_hor_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:46:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/01 14:51:42 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	horizontal_rh_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->x < line.p2->x)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->x += 1;
	}
}

void	horizontal_lh_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->x > line.p2->x)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->x -= 1;
	}
}

void	vertical_up_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->z < line.p2->z)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->z += 1;
	}
}

void	vertical_dw_line(t_data *data, t_line line, char option)
{
	(void)option;
	while (line.p1->z > line.p2->z)
	{
		pixel_put(data, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->z -= 1;
	}
}
