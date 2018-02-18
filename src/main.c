/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:03:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/18 20:49:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main()
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point2d	p1;
	t_point2d	p2;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "TO!!");
	p1.x = 400;
	p1.z = 200;
	p2.x = 350;
	p2.z = 10;
	trace_line(mlx_ptr, win_ptr, p1, p2);
	mlx_loop(mlx_ptr);
}
