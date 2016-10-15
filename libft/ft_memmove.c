/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 10:24:45 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/23 18:06:08 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	s = s + len;
	d = d + len;
	while (len--)
	{
		*--d = *--s;
	}
	return (dst);
}
