/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:06:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 12:51:28 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define ALPHA 45.
# define COEF 1.

typedef struct	s_point3d
{
	int		x;
	int		y;
	int		z;
}				t_point3d;

typedef struct	s_point2d
{
	double		x;
	double		z;
}				t_point2d;

typedef struct	s_line
{
	int			dx;
	int			dz;
	t_point2d	*p1;
	t_point2d	*p2;
}				t_line;

t_point3d		**init_tab3d(char *file, t_point3d ***tab, int *x_max, int *z_max);
t_point2d		**init_tab2d(int x_max, int z_max);
void			free_tab3d(t_point3d ***tab, int z_max);
void			free_tab2d(t_point2d ***tab, int z_max);
int				parser(char *file, t_point3d **tab);
void			print_tab3d(t_point3d **tab, int x_max, int z_max);
void			print_tab2d(t_point2d **tab, int x_max, int z_max);
void			proj_cav(t_point3d **tab3, t_point2d **tab2, int x_max, int z_max);

void			trace_line(void *mlw_ptr, void *win_ptr, t_point2d p1, t_point2d p2);
void			twd_right_line(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_1(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_2(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_8(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_7(void *mlw_ptr, void *win_ptr, t_line line);
void			twd_left_line(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_4(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_3(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_5(void *mlw_ptr, void *win_ptr, t_line line);
void			octant_6(void *mlw_ptr, void *win_ptr, t_line line);
void			horizontal_RH_line(void *mlw_ptr, void *win_ptr, t_line line);
void			horizontal_LH_line(void *mlw_ptr, void *win_ptr, t_line line);
void			vertical_UP_line(void *mlw_ptr, void *win_ptr, t_line line);
void			vertical_DW_line(void *mlw_ptr, void *win_ptr, t_line line);

#endif

