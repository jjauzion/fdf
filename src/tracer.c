/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:18:09 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/20 20:11:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	trace_grid(void *mlx_ptr, void *win_ptr, t_point2d **tab, int jmax, int imax)
{
	int	i;
	int	j;

	i = -1;
	while (++i < imax)
	{
		j = -1;
		while (++j < jmax)
		{
			trace_line(mlx_ptr, win_ptr, tab[i][j], tab[i][j + 1]);
			trace_line(mlx_ptr, win_ptr, tab[i][j], tab[i + 1][j]);
		}
		trace_line(mlx_ptr, win_ptr, tab[i][j], tab[i + 1][j]);
	}
	j = -1;
	while (++j < jmax)
		trace_line(mlx_ptr, win_ptr, tab[imax][j], tab[imax][j + 1]);
}

void		tracer(t_point3d **tab3, t_point2d **tab, int j_max, int i_max, int width, int height)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_view_data	view;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "fdf");
	trace_grid(mlx_ptr, win_ptr, tab, j_max, i_max);
	view.mlx = mlx_ptr;
	view.win = win_ptr;
	view.tab3 = tab3;
	view.tab2 = tab;
	view.imax = i_max;
	view.jmax = j_max;
	view.height_factor = 1;
	mlx_key_hook(win_ptr, key_hook, (void*)&view);
	mlx_loop(mlx_ptr);
}
