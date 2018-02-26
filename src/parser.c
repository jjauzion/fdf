/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:11:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/26 17:00:28 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	parse_line(char *line, t_point3d *tab, int z)
{
	char		**value;
	int			x;
	intmax_t	tmp;

	if (!(value = ft_strsplit(line, ' ')))
		return (1);
	if (!value[0])
		return (1);
	x = 0;
	while (value[x])
	{
		tab[x].x = x * DEF_SCALE;
		tab[x].z = z * DEF_SCALE;
		if (ft_isnumber(value[x]))
			if ((tmp = ft_atoim(value[x])) > INT_MAX || tmp < INT_MIN)
				return (1);
			else
				tab[x].y = ft_atoi(value[x]);
		else
			return (1);
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

int			parser(char *file, t_point3d **tab)
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
	if (z == 0)
		return (1);
	ft_strdel(&line);
	close(fd);
	return (0);
}
