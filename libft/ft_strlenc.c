/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:47:45 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:47:48 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	if (s)
		while (s[ret] != c && s[ret])
			++ret;
	return (ret);
}
