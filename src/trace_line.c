/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:41:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/18 20:46:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	twd_right_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	if (line.dz > 0)
	{
		if (line.dx >= line.dz)
			octant_1(mlx_ptr, win_ptr, line);
		else
			octant_2(mlx_ptr, win_ptr, line);
	}
	else if (line.dz < 0)
	{
		if (line.dx >= -line.dz)
			octant_8(mlx_ptr, win_ptr, line);
		else
			octant_7(mlx_ptr, win_ptr, line);
	}
//	else
//		horizontal_line(mlx_ptr, win_ptr, line);
}

void	twd_left_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	if (line.dz > 0)
	{
		if (-line.dx >= line.dz)
			octant_4(mlx_ptr, win_ptr, line);
		else
			octant_3(mlx_ptr, win_ptr, line);
	}
	else if (line.dz < 0)
	{
		if (line.dx <= line.dz)
			octant_5(mlx_ptr, win_ptr, line);
		else
			octant_6(mlx_ptr, win_ptr, line);
	}
//	else
//		horizontal_line(mlx_ptr, win_ptr, line);
}

void	trace_line(void *mlx_ptr, void *win_ptr, t_point2d p1, t_point2d p2)
{
	t_line	line;

	line.dx = p2.x - p1.x;
	line.dz = p2.z - p1.z;
	line.p1 = &p1;
	line.p2 = &p2;
	if (line.dx > 0)
		twd_right_line(mlx_ptr, win_ptr, line);
	else if (line.dx < 0)
		twd_left_line(mlx_ptr, win_ptr, line);
/*	else
		vertical_line(mlx_ptr, win_ptr, line);
*/}
