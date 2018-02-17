/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:20:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 14:21:07 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(int c)
{
	c = ft_toupper(c);
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}
