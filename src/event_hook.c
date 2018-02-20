/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:33:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/20 19:52:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_hook(int keycode, void *param)
{
	(void)param;

	ft_printf("%d\n", keycode);
	if (keycode != 53)
		update_view(keycode, param);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
