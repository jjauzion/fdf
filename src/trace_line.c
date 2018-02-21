/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:41:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 16:15:24 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	twd_right_line(t_data *data, t_line line, char option)
{
	if (line.dz > 0)
	{
		if (line.dx >= line.dz)
			octant_1(data, line, option);
		else
			octant_2(data, line, option);
	}
	else if (line.dz < 0)
	{
		if (line.dx >= -line.dz)
			octant_8(data, line, option);
		else
			octant_7(data, line, option);
	}
	else
		horizontal_RH_line(data, line, option);
}

void	twd_left_line(t_data *data, t_line line, char option)
{
	if (line.dz > 0)
	{
		if (-line.dx >= line.dz)
			octant_4(data, line, option);
		else
			octant_3(data, line, option);
	}
	else if (line.dz < 0)
	{
		if (line.dx <= line.dz)
			octant_5(data, line, option);
		else
			octant_6(data, line, option);
	}
	else
		horizontal_LH_line(data, line, option);
}

void	trace_line(t_data *data, t_point2d p1, t_point2d p2,  char option)
{
	t_line	line;

	(void)option;
	line.dx = p2.x - p1.x;
	line.dz = p2.z - p1.z;
	line.p1 = &p1;
	line.p2 = &p2;
	if (line.dx > 0)
		twd_right_line(data, line, option);
	else if (line.dx < 0)
		twd_left_line(data, line, option);
	else if (line.dz > 0)
		vertical_UP_line(data, line, option);
	else if (line.dz < 0)
		vertical_DW_line(data, line, option);
}
