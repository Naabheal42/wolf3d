/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:47:27 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:47:30 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyc(char *dst, char *src, char c)
{
	char	*orig;

	orig = dst;
	while (*src != c && *src)
		*dst++ = *src++;
	*dst = 0;
	return (orig);
}
