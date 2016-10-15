/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:49:24 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/23 17:59:06 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] - s2[i] == 0)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
