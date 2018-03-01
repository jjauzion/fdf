/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:06:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/01 14:48:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIN_MARGIN 50 
# define DEF_SCALE 20 
# define DEF_SHIFT 20 
# define ROT_ANGLE 10. 
# define MAX_WIDTH 1600
# define MAX_HEIGHT 1000
# define ZOOM 2.

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
	int			height;
}				t_point2d;

typedef struct	s_line
{
	int			dx;
	int			dz;
	t_point2d	*p1;
	t_point2d	*p2;
}				t_line;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_point2d	**tab2;
	t_point3d	**tab3;
	t_point3d	**transtab3;
	int			x_offset;
	int			z_offset;
	int			imax;
	int			jmax;
	int			height_factor;
	double		zoom;
	double		init_zoom;
	int			translation[2];
	double		rotation[3];
	char		option;
	int			**color;
	int			win_width;
	int			win_height;
}				t_data;

int				ft_rgb2tsv(int rgb, int *t, int *s, int *v);
int				ft_tsv2rgb(int t, int s, int v);

t_point2d		**init_tab2d(t_point3d **tab3, int jmax, int imax);
int				init_tab3d(char *file, t_data *data);
void			init_param(t_data *data);
t_point3d		**malloc_tab3(int x_max, int z_max);
t_point2d		**malloc_tab2(int x_max, int z_max);
void			free_tab3d(t_point3d ***tab, int z_max);
void			free_tab2d(t_point2d ***tab, int z_max);
int				parser(char *file, t_point3d **tab);
void			display(t_data *data, int width, int height);
void			trace_grid(t_data *data, char option);
void			proj_iso(t_data *data);
void			center2camera(t_data *data, int *win_width, int *win_height);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
void			print2screen(void *param, int key, int x, int y);
void			translation(t_data *data, t_point3d **tab3, int x_off, int z_off);
void			scale_factor(t_data *data, t_point3d **tab3, double factor);
void			zoom(t_data *data, int x, int y, char option);
void			rotation_x(t_data *data, t_point3d **tab, double angle);
void			rotation_y(t_data *data, t_point3d **tab, double angle);
void			pixel_put(t_data *data, t_point2d *p, int height, char option);
int				**color_scale(void);

void			trace_line(t_data *data, t_point2d p1, t_point2d p2, char option);
void			twd_right_line(t_data *data, t_line line, char option);
void			octant_1(t_data *data, t_line line, char option);
void			octant_2(t_data *data, t_line line, char option);
void			octant_8(t_data *data, t_line line, char option);
void			octant_7(t_data *data, t_line line, char option);
void			twd_left_line(t_data *data, t_line line, char option);
void			octant_4(t_data *data, t_line line, char option);
void			octant_3(t_data *data, t_line line, char option);
void			octant_5(t_data *data, t_line line, char option);
void			octant_6(t_data *data, t_line line, char option);
void			horizontal_rh_line(t_data *data, t_line line, char option);
void			horizontal_lh_line(t_data *data, t_line line, char option);
void			vertical_up_line(t_data *data, t_line line, char option);
void			vertical_dw_line(t_data *data, t_line line, char option);

void			print_tab3d(t_point3d **tab, int x_max, int z_max);
void			print_tab2d(t_point2d **tab, int x_max, int z_max);
void			print_tab3dxz(t_point3d **tab, int x_max, int z_max);
void			print_tab2dxz(t_point2d **tab, int x_max, int z_max);

#endif

