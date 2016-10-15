/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:45:42 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/16 12:10:02 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	while (len > 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	if (len == 0 && s[len] == c)
		return ((char *)s + len);
	return (NULL);
}
