/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:03:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/20 20:16:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_point3d	**tab3;
	t_point2d	**tab2;
	int			x_max;
	int			z_max;
	int			win_width;
	int			win_height;

	if (argc != 2)
	{
		perror("Error ");
		return (1);
	}
	if (!(tab3 = init_tab3d(argv[1], &x_max, &z_max)))
		return (1);
	parser(argv[1], tab3);
	if (!(tab2 = malloc_tab2(x_max, z_max)))
		return (1);
	center2camera(tab3, x_max, z_max, &win_width, &win_height);
	proj_iso(tab3, tab2, x_max, z_max, 1);
	tracer(tab3, tab2, x_max, z_max, win_width, win_height);
	free_tab3d(&tab3, z_max);
	free_tab2d(&tab2, z_max);
}
