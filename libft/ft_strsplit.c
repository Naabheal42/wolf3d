/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 15:57:03 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:48:40 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_splitstr(char **tab, char *s, char c, t_uint len)
{
	t_uint	i;

	i = 0;
	while (*s == c && *s)
		++s;
	while (i < len)
	{
		if ((tab[i] = ft_strdupc(s, c)) == NULL)
			return (0);
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
		++i;
	}
	tab[i] = 0;
	return (1);
}

static t_uint	ft_split_count(char *s, char c)
{
	t_uint	ret;

	ret = 0;
	while (*s == c)
		++s;
	while (*s)
	{
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
		++ret;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	t_uint	len;

	ret = NULL;
	if (s)
	{
		len = ft_split_count((char*)s, c);
		if ((ret = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
			return (NULL);
		if (ft_splitstr(ret, (char*)s, c, len))
			return (ret);
		else
		{
			free(ret);
			ret = NULL;
		}
	}
	return (ret);
}
