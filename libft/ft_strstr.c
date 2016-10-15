/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:58:06 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/23 17:38:12 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[k])
	{
		while (s1[i])
		{
			j = 0;
			while (s1[i++] == s2[j++])
				if (s2[j] == '\0')
					return ((char *)s1 + (i - j));
			if (s1[i] == s2[0])
				i--;
			i++;
		}
		k++;
		i = k;
	}
	return (NULL);
}
