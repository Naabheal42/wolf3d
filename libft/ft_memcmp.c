/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:10:49 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/09 13:02:28 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *p1;
	const char *p2;

	p1 = (const char*)s1;
	p2 = (const char*)s2;
	if (!p1 || !p2)
		return (0);
	while (n--)
	{
		if (*p1 != *p2)
			return ((unsigned char)*p1 - (unsigned char)*p2);
		p1++;
		p2++;
	}
	return (0);
}
