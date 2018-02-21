/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:24:05 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/18 18:48:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int		deal_key(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putchar('X');	
	return (0);
}

void	ft_trace_line(void *mlx_ptr, void *win_ptr, t_point2d p1, t_point2d p2)
{
	int	dx;
	int dy;
	int	err;

	err = p2.x - p1.x;
	dx = err * 2;
	dy = (p2.z - p1.z) * 2;
	while (p1.x < p2.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p1.x, p1.z, 0xFF0000);
		p1.x = p1.x + 1;
		if ((err = err - dy) <= 0 )
		{
			p1.z = p1.z + 1;
			err = err - dx;
		}
	}
}

void	init_tab(t_point3d tab[8])
{
	tab[0].x = 1;
	tab[0].y = 0;
	tab[0].z = 1;
	tab[1].x = 1;
	tab[1].y = 0;
	tab[1].z = 2;
	tab[2].x = 2;
	tab[2].y = 0;
	tab[2].z = 2;
	tab[3].x = 2;
	tab[3].y = 0;
	tab[3].z = 1;
	tab[4].x = 1;
	tab[4].y = 1;
	tab[4].z = 1;
	tab[5].x = 1;
	tab[5].y = 1;
	tab[5].z = 2;
	tab[6].x = 2;
	tab[6].y = 1;
	tab[6].z = 2;
	tab[7].x = 2;
	tab[7].y = 1;
	tab[7].z = 1;
}

void	zoom(t_point2d tab[8], int size, int zoom)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		tab[i].x = tab[i].x * (double)zoom;
		tab[i].z = tab[i].z * (double)zoom;
	}
}

void	projection(t_point3d tab3d[8], t_point2d tab2d[8], int size)
{
	int		i;
	double	rad_a;

	rad_a = ALPHA * M_PI / 180.;
	printf("rad angle = %f\n", rad_a);
	i = -1;
	while (++i < size)
	{
		tab2d[i].x = (double)tab3d[i].x + COEF * cos(rad_a) * (double)tab3d[i].y;
		tab2d[i].z = (double)tab3d[i].z - COEF * sin(rad_a) * (double)tab3d[i].y;
	}
}

void	trace_cube(void *mlx_ptr, void *win_ptr, t_point2d tab[8], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		mlx_string_put(mlx_ptr, win_ptr, (int)tab[i].x, (int)tab[i].z, 0xFFFFFF, ft_itoa(i));
	}
}

void	print_tab2d(t_point2d tab[8])
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		printf("tab[%2d].x = %4f\n", i, tab[i].x);
		printf("tab[%2d].z = %4f\n", i, tab[i].z);
	}
}

int		main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point3d	tab3d[8];
	t_point2d	tab2d[8];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "TO!!");
	init_tab(tab3d);
	projection(tab3d, tab2d, 8);
	print_tab2d(tab2d);
	getchar ();
	zoom(tab2d, 8, 100);
	print_tab2d(tab2d);
	getchar ();
	trace_cube(mlx_ptr, win_ptr, tab2d, 8);
	mlx_loop(mlx_ptr);
}

/*
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0x4AFF3D, "coucou");
	p1.x = 100;
	p1.y = 100;
	p2.x = 400;
	p2.y = 3000;
	ft_trace_line(mlx_ptr, win_ptr, p1, p2);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
*/
