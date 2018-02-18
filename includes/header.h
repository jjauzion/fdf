/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:06:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/18 20:44:46 by jjauzion         ###   ########.fr       */
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

#endif

