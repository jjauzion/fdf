/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:11:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 12:02:42 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	parse_line(char *line, t_point3d *tab, int z)
{
	char		**value;
	int			x;

	if (!(value = ft_strsplit(line, ' ')))
		return (1);
	x = 0;
	while (value[x])
	{
		tab[x].x = x;
		tab[x].z = z;
		tab[x].y = ft_atoi(value[x]);
		x++;
	}
	while (x >= 0)
	{
		ft_strdel(&value[x]);
		x--;
	}
	free(value);
	return (0);
}

int		parser(char *file, t_point3d **tab)
{
	int			fd;
	int			ret;
	char		*line;
	int			z;

	if (!file)
		return (1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	z = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (parse_line(line, tab[z], z))
			return (1);
		z++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (0);
}
