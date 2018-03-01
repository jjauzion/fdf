/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:03:52 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/01 15:59:55 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		print_tab2d(t_point2d **tab, int x_max, int z_max)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= z_max)
	{
		j = -1;
		while (++j <= x_max)
			printf("% 6.2f ", tab[i][j].z);
		printf("\n");
	}
}

void		print_tab2dxz(t_point2d **tab, int x_max, int z_max)
{
	int	i;
	int	j;

	ft_printf("  x   z   y\n");
	i = -1;
	while (++i <= z_max)
	{
		j = -1;
		while (++j <= x_max)
		{
			printf("% 6.2f ", tab[i][j].x);
			printf("% 6.2f ", tab[i][j].z);
			printf("% 6.2d ", tab[i][j].height);
			printf("\n");
		}
	}
}

void		print_tab3dxz(t_point3d **tab, int x_max, int z_max)
{
	int	i;
	int	j;

	ft_printf("  x   z   y\n");
	i = -1;
	while (++i <= z_max)
	{
		j = -1;
		while (++j <= x_max)
		{
			ft_printf("% 2d ", tab[i][j].x);
			ft_printf("% 2d ", tab[i][j].z);
			ft_printf("% 2d ", tab[i][j].y);
			ft_printf("\n");
		}
	}
}

void		print_tab3d(t_point3d **tab, int x_max, int z_max)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= z_max)
	{
		j = -1;
		while (++j <= x_max)
			ft_printf("%2d ", tab[i][j].y);
		ft_printf("\n");
	}
}
