/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twd_left_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:35:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/18 20:44:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	octant_4(void *mlx_ptr, void *win_ptr, t_line line)
{
	int	err;

	err = line.dx;
	line.dx = line.dx * 2;
	line.dz = line.dz * 2;
	while (line.p1->x > line.p2->x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->x -= 1;
		if ((err = err + line.dz) >= 0)
		{
			line.p1->z += 1;
			err = err + line.dx;
		}
	}
}

void	octant_3(void *mlx_ptr, void *win_ptr, t_line line)
{
	int	err;

	err = line.dz;
	line.dx = line.dx * 2;
	line.dz = line.dz * 2;
	while (line.p1->z < line.p2->z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->z += 1;
		if ((err = err + line.dx) <= 0)
		{
			line.p1->x -= 1;
			err = err + line.dz;
		}
	}
}

void	octant_5(void *mlx_ptr, void *win_ptr, t_line line)
{
	int	err;

	err = line.dx;
	line.dx = line.dx * 2;
	line.dz = line.dz * 2;
	while (line.p1->x > line.p2->x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->x -= 1;
		if ((err = err - line.dz) >= 0)
		{
			line.p1->z -= 1;
			err = err + line.dx;
		}
	}
}

void	octant_6(void *mlx_ptr, void *win_ptr, t_line line)
{
	int	err;

	err = line.dz;
	line.dx = line.dx * 2;
	line.dz = line.dz * 2;
	while (line.p1->z > line.p2->z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->z -= 1;
		if ((err = err - line.dx) >= 0)
		{
			line.p1->x -= 1;
			err = err + line.dz;
		}
	}
}
