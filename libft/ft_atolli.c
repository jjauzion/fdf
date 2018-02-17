/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:50:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/13 15:52:35 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atolli(const char *str)
{
	long long int	nbr;
	int				sign;

	sign = 1;
	nbr = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
				|| *str == '\r' || *str == '\f') && *str)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (long long int)(*str - 48);
		str++;
	}
	return (nbr * (long long int)sign);
}
