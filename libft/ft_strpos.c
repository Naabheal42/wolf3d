/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:25:55 by nbrizini          #+#    #+#             */
/*   Updated: 2015/01/16 15:52:32 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strpos(const char *s1, const char *s2)
{
	char	*s1_;
	char	*s2_;
	int		l;
	int		counter;

	counter = 0;
	s1_ = (char *)s1;
	s2_ = (char *)s2;
	l = ft_strlen(s2_);
	while (*s1_ != '\0')
	{
		if (ft_strncmp(s1_, s2_, l) == 0)
			return (counter);
		s1_++;
		counter++;
	}
	return (counter);
}
