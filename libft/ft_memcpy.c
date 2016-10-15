/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:49:43 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/09 10:34:13 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;
	char	*q;
	size_t	i;

	i = 0;
	p = (char*)dst;
	q = (char*)src;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dst);
}
