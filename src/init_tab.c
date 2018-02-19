/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:11:04 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 19:48:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_xmax(char *line)
{
	char	**value;
	int		x_max;

	if (!(value = ft_strsplit((const char*)line, ' ')))
		return (-1);
	x_max = 0;
	while (value[x_max])
	{
		ft_strdel(&value[x_max]);
		x_max++;
	}
	ft_strdel(&value[x_max]);
	free(value);
	return (x_max - 1);
}

t_point3d	**init_tab3d(char *file, t_point3d ***tab, int *x_max, int *z_max)
{
	char	*line;
	int		ret;
	int		i;
	int		fd;
	int		tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	*z_max = -1;
	*x_max = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		(*z_max)++;
		if (*x_max < 0)
			*x_max = get_xmax(line);
		else if ((tmp = get_xmax(line)) != *x_max)
			return (NULL);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!(*tab = (t_point3d**)malloc(sizeof(t_point3d*) * (*z_max + 1))))
		return (NULL);
	i = *z_max + 1;
	while (--i >= 0)
		if (!((*tab)[i] = (t_point3d*)malloc(sizeof(t_point3d) * (*x_max + 1))))
			return (NULL);
	close(fd);
	return (*tab);
}

t_point2d	**init_tab2d(int x_max, int z_max)
{
	t_point2d	**tab;

	if (!(tab = (t_point2d**)malloc(sizeof(t_point2d*) * (z_max + 1))))
		return (NULL);
	while (z_max >= 0)
	{
		if (!(tab[z_max] = (t_point2d*)malloc(sizeof(t_point2d) * (x_max + 1))))
			return (NULL);
		z_max--;
	}
	return (tab);
}
