/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:52:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 10:01:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Check if the string given in input contain a well formatted number so that
**	it can be passed safely to ft_atoi function.
**	Returns 1 if the input string contains a well formated number for atoi.
**	Returns 0 otherwise.
*/

#include "libft.h"

int		ft_isnumber(char *str)
{
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n' ||
				*str == '\r' || *str == '\f') && *str)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (ft_isdigit(*str))
		return (1);
	else
		return (0);
}
