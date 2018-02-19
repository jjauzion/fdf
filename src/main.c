/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:03:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 12:52:18 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_point3d	**tab3;
	t_point2d	**tab2;
	int			x_max;
	int			z_max;

	if (argc != 2)
		return (1);
	if (!(tab3 = init_tab3d(argv[1], &tab3, &x_max, &z_max)))
		return (1);
	parser(argv[1], tab3);
	print_tab3d(tab3, x_max, z_max);
	if (!(tab2 = init_tab2d(x_max, z_max)))
		return (1);
	proj_cav(tab3, tab2, x_max, z_max);
ft_printf("YOOOOO!!!\n");
	print_tab2d(tab2, x_max, z_max);
	free_tab3d(&tab3, z_max);
	free_tab2d(&tab2, z_max);
/*	void		*mlx_ptr;
	void		*win_ptr;
	t_point2d	p1;
	t_point2d	p2;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "TO!!");
	p1.x = 200;
	p1.z = 200;
	p2.x = 400;
	p2.z = 200;
	trace_line(mlx_ptr, win_ptr, p1, p2);
	mlx_loop(mlx_ptr);*/
}
