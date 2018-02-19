/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:29:08 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 12:29:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_tab2d(t_point2d ***tab, int z_max)
{
	while (z_max >= 0)
	{
		free((*tab)[z_max]);
		z_max--;
	}
	free(*tab);
}

void	free_tab3d(t_point3d ***tab, int z_max)
{
	while (z_max >= 0)
	{
		free((*tab)[z_max]);
		z_max--;
	}
	free(*tab);
}
