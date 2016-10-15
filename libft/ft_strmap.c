/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:12:56 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/23 18:19:04 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		new = (char*)malloc(sizeof(char) * (len + 1));
		if (!new)
			return (NULL);
		while (i < len)
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = 0;
		return (new);
	}
	return (NULL);
}
