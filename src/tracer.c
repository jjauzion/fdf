/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:18:09 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 18:55:47 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	trace_grid(void *mlx_ptr, void *win_ptr, t_point2d **tab, t_limit limit)
{
	int	i;
	int	j;

	i = -1;
	while (++i < limit.i)
	{
		j = -1;
		while (++j < limit.j)
		{
			trace_line(mlx_ptr, win_ptr, tab[i][j], tab[i][j + 1]);
			trace_line(mlx_ptr, win_ptr, tab[i][j], tab[i + 1][j]);
		}
		trace_line(mlx_ptr, win_ptr, tab[i][j], tab[i + 1][j]);
	}
	j = -1;
	while (++j < limit.j)
		trace_line(mlx_ptr, win_ptr, tab[limit.i][j], tab[limit.i][j + 1]);
}

void		tracer(t_point2d **tab, int j_max, int i_max, int width, int height)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_limit	limit;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "fdf");
	limit.i = i_max;
	limit.j = j_max;
	trace_grid(mlx_ptr, win_ptr, tab, limit);
	mlx_loop(mlx_ptr);
}
