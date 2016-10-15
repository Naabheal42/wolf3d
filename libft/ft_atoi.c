/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:40:59 by nbrizini          #+#    #+#             */
/*   Updated: 2015/01/21 11:32:51 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		nbr;
	int		neg;

	nbr = 0;
	neg = 0;
	while (*str == ' ' || *str == '\n' || *str == '\r' || *str == '\t'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + *str - '0';
		str++;
	}
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}
