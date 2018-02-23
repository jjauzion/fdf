/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:26:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/23 16:48:52 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	mountains(int **scale)
{
	scale[0][0] = 5;
	scale[0][1] = 1;
	scale[1][1] = 0x1962E1;
	scale[0][2] = 1;
	scale[1][2] = 0x009A00;
	scale[0][3] = 20;
	scale[1][3] = 0x9A5700;
	scale[0][4] = 80;
	scale[1][4] = 0x402400;
	scale[0][5] = 80;
	scale[1][5] = 0xFFFFFF;
}

int			**color_scale(char *scale_color)
{
	int	**scale;
	int	i;

	if (!(scale = (int**)malloc(sizeof(int*) * 6)))
		return (NULL);
	i = -1;
	while (++i < 6)
		if (!(scale[i] = (int*)malloc(sizeof(int) * 2)))
			return (NULL);
	if (ft_strequ(scale_color, "MOUTAINS"))
		mountains(scale);
	else
		scale[0][0] = 0;
	return (scale);
}
