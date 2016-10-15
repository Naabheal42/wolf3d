/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:53:52 by nbrizini          #+#    #+#             */
/*   Updated: 2014/12/01 10:16:21 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t ex, size_t len)
{
	void	*new;

	if (p == NULL)
		return (NULL);
	if (len == 0)
		new = (void *)ft_memalloc(sizeof(char));
	else
		new = (void *)ft_memalloc(len);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, (len) ? len : sizeof(char));
	if (ex > len)
		ft_memcpy(new, p, (len) ? len : sizeof(char));
	else
		ft_memcpy(new, p, ex);
	ft_memdel((void *)&p);
	return (new);
}
