/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:33:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/25 15:21:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_hook(int keycode, void *param)
{
	print2screen(param, keycode, -1, -1);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	printf("button = %d ; x = %d ; y = %d\n", button, x, y);
	print2screen(param, button * -1, x, y);
	return(0);
}
