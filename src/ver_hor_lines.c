/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_hor_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:46:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 09:58:03 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	horizontal_RH_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	while (line.p1->x < line.p2->x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->x += 1;
	}
}

void	horizontal_LH_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	while (line.p1->x > line.p2->x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->x -= 1;
	}
}

void	vertical_UP_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	while (line.p1->z < line.p2->z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->z += 1;
	}
}

void	vertical_DW_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	while (line.p1->z > line.p2->z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.p1->x, line.p1->z, 0xFFFFFF);
		line.p1->z -= 1;
	}
}
