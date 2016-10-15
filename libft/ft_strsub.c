/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:30:21 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/23 19:17:15 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new || !s)
		return (NULL);
	i = 0;
	if (s)
	{
		while (i < len && s[start])
		{
			new[i] = s[start];
			i++;
			start++;
		}
		new[i] = 0;
	}
	return (new);
}
