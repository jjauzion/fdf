/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:03:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/23 16:43:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int			win_width;
	int			win_height;
	t_data		data;

	if (argc != 2)
	{
		perror("Error ");
		return (1);
	}
	data.option = '\0';
	if (!(data.tab3 = init_tab3d(argv[1], &data)))
		return (1);
	parser(argv[1], data.tab3);
	if (!(data.tab2 = malloc_tab2(data.jmax, data.imax)))
		return (1);
	center2camera(&data, &win_width, &win_height);
	data.height_factor = 1;
	data.color = color_scale("MOUTAINS");
	display(&data, win_width, win_height);
	return (0);
}
