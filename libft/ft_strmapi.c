/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:10:24 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/23 18:20:04 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		new = (char*)malloc(sizeof(char) * len);
		if (!new)
			return (NULL);
		while (i < len)
		{
			new[i] = f(i, s[i]);
			i++;
		}
		new[i] = 0;
		return (new);
	}
	return (NULL);
}
