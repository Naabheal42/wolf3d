/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 10:49:36 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/10 11:43:44 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	size_t		i;

	i = 0;
	src = (char*)s;
	if (s && n > 0)
	{
		while (i < n)
		{
			if ((unsigned char)src[i] == (unsigned char)c)
				return ((void*)s + i);
			i++;
		}
	}
	return (NULL);
}
