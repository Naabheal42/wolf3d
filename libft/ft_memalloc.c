/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:41:23 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/09 14:59:14 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;
	char	*tmp;
	size_t	i;

	i = 0;
	p = (void*)malloc(sizeof(void) * size);
	if (!p)
		return (NULL);
	tmp = (char*)p;
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (p);
}
