/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:11:04 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/22 20:28:49 by jjauzion         ###   ########.fr       */
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

t_point2d	**malloc_tab2(int x_max, int z_max)
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

t_point2d	**init_tab2d(t_point3d **tab3, int x_max, int z_max)
{
	t_point2d	**tab2;
	
	if(!(tab2 = malloc_tab2(x_max, z_max)))
		return (NULL);
	while (z_max >= 0)
	{
		while (x_max >= 0)
		{
			tab2[z_max][x_max].height = tab3[z_max][x_max].y;
			x_max--;
		}
		z_max--;
	}
	return (tab2);
}


t_point3d	**malloc_tab3(int x_max, int z_max)
{
	t_point3d	**tab;
	int			i;

	if (!(tab = (t_point3d**)malloc(sizeof(t_point3d*) * (z_max + 1))))
		return (NULL);
	i = z_max + 1;
	while (--i >= 0)
		if (!(tab[i] = (t_point3d*)malloc(sizeof(t_point3d) * (x_max + 1))))
			return (NULL);
	return (tab);
}

t_point3d	**init_tab3d(char *file, t_data *data)
{
	char		*line;
	int			ret;
	int			fd;
	int			tmp;
	t_point3d	**tab;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	data->imax = -1;
	data->jmax = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		(data->imax)++;
		if (data->jmax < 0)
			data->jmax = get_xmax(line);
		else if ((tmp = get_xmax(line)) != data->jmax)
			return (NULL);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	tab = malloc_tab3(data->jmax, data->imax);
	close(fd);
	return (tab);
}
