/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:37:39 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/13 18:58:07 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	new = (char*)malloc(sizeof(char) * ft_strlen(s));
	if (!new)
		return (NULL);
	while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
		start++;
	while (s[end] == '\t' || s[end] == '\n' || s[end] == ' ')
		end--;
	while (start <= end)
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}
