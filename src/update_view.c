/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:57:30 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/20 20:18:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_view(int key, void *param)
{
	t_view_data	*view;

	view = (t_view_data*)param;
	if (key == 78)
		view->height_factor--;
	if (key == 69)
		view->height_factor++;
	proj_iso(view->tab3, view->tab2, view->jmax, view->imax, view->height_factor);
	trace_grid(view->mlx, view->win, view->tab2, view->jmax, view->imax);
}
