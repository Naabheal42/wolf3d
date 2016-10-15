/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:47:57 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:47:58 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupc(const char *s1, char c)
{
	char	*ret;

	ret = NULL;
	if (s1)
	{
		if ((ret = (char*)malloc(ft_strlenc((char*)s1, c) + 1)) == NULL)
			return (NULL);
		ft_strcpyc(ret, (char*)s1, c);
	}
	return (ret);
}
