/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:39:53 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/10 14:10:51 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char*)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	new[i] = 0;
	return (new);
}
