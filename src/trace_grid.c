/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:09:09 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/21 16:06:26 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	trace_grid(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->imax)
	{
		j = -1;
		while (++j < data->jmax)
		{
			trace_line(data, data->tab2[i][j], data->tab2[i][j + 1], ' ');
			trace_line(data, data->tab2[i][j], data->tab2[i + 1][j], ' ');
		}
		trace_line(data, data->tab2[i][j], data->tab2[i + 1][j], ' ');
	}
	j = -1;
	while (++j < data->jmax)
		trace_line(data, data->tab2[data->imax][j], data->tab2[data->imax][j + 1], ' ');
}
