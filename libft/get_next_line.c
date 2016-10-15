/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:52:20 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:52:31 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlenn(char *str)
{
	int			i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strdupp(char *str)
{
	int			i;
	char		*new;

	i = 0;
	new = NULL;
	if (str == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlenn(str) + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char		*ft_strcatt(char *s1, char *s2)
{
	int			i;
	int			j;
	int			len;
	char		*new;

	i = 0;
	j = 0;
	len = (ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
			new[i++] = s2[j++];
	}
	new[i] = '\0';
	return (new);
}

static int		ft_search_n_save(char *bkp, char **tmp, char **line)
{
	int			i;

	i = 0;
	while (bkp[i] != '\0')
	{
		if (bkp[i] == '\n' || bkp[i + 1] == 26)
		{
			bkp[i++] = '\0';
			*tmp = NULL;
			*tmp = ft_strdupp(&bkp[i]);
			*line = ft_strdupp(bkp);
			bkp = NULL;
			return (1);
		}
		i++;
	}
	*tmp = NULL;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*tmp = "";
	char		*bkp;
	char		*buff;
	int			ret;

	bkp = NULL;
	buff = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || tmp)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		bkp = ft_strcatt(bkp, tmp);
		bkp = ft_strcatt(bkp, buff);
		if (ft_search_n_save(bkp, &tmp, line) == 1)
			return (1);
	}
	if (bkp && *bkp && ret == 0)
	{
		*line = ft_strdupp(bkp);
		return (1);
	}
	return (0);
}
