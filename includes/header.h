/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:06:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/20 20:17:02 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIN_MARGIN 50 
# define DEF_SCALE 20 
# define MAX_WIDTH 1600
# define MAX_HEIGHT 1000

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

typedef struct	s_limit
{
	int			i;
	int			j;
}				t_limit;

typedef struct	s_line
{
	int			dx;
	int			dz;
	t_point2d	*p1;
	t_point2d	*p2;
}				t_line;

typedef struct	s_view_data
{
	void		*mlx;
	void		*win;
	t_point3d	**tab3;
	t_point2d	**tab2;
	int			imax;
	int			jmax;
	int			height_factor;
}				t_view_data;

t_point3d		**init_tab3d(char *file, int *x_max, int *z_max);
t_point3d		**malloc_tab3(int x_max, int z_max);
t_point2d		**malloc_tab2(int x_max, int z_max);
void			free_tab3d(t_point3d ***tab, int z_max);
void			free_tab2d(t_point2d ***tab, int z_max);
int				parser(char *file, t_point3d **tab);
void			print_tab3d(t_point3d **tab, int x_max, int z_max);
void			print_tab2d(t_point2d **tab, int x_max, int z_max);
void			tracer(t_point3d **tab3, t_point2d **tab, int j_max, int i_max, int width, int height);
void			trace_grid(void *mlx_ptr, void *win_ptr, t_point2d **tab, int j_max, int i_max);
void			proj_cav(t_point3d **tab3, t_point2d **tab2, int x_max, int z_max);
void			proj_iso(t_point3d **tab3, t_point2d **tab2, int x_max, int z_max, int factor);
void			translation(t_point2d **tab, int x_max, int z_max, int x_off, int z_off);
void			translation3d(t_point3d **tab, int x_max, int z_max, int x_off, int z_off);
void			scale_factor(t_point2d **tab, int x_max, int z_max, double factor);
void			scale_factor3d(t_point3d **tab, int x_max, int z_max, double factor);
void			center2window(t_point2d **tab, int j_max, int i_max, int *win_width, int *win_height);
void			center2camera(t_point3d **tab, int j_max, int i_max, int *win_width, int *win_height);
int				key_hook(int keycode, void *param);
void			update_view(int key, void *param);

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

