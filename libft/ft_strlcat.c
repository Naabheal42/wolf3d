/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:59:04 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/24 09:44:34 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	char	*tmp;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	tmp = dst;
	if (size < ldst + 1)
		return (lsrc + size);
	else
	{
		ft_memcpy(tmp + ldst, src, sizeof(char) * (size - ldst - 1));
		dst[size - 1] = '\0';
	}
	return (ldst + lsrc);
}
