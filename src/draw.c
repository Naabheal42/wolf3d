/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:23:58 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 16:57:42 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map_put_wall(int i, int j, t_env *e)
{
	if (i == 0 || j == 0 || i == 23 || j == 23)
		e->worldmap[i][j] = 1;
	if (i == 4 && j >= 4 && j <= 10)
		e->worldmap[i][j] = 2;
	if (i == 8 && j >= 4 && j <= 10)
		e->worldmap[i][j] = 2;
	if (j == 4 && i >= 4 && i <= 8)
		e->worldmap[i][j] = 2;
	if (i == 6 && j == 6)
		e->worldmap[i][j] = 5;
	if (j == 10 && i >= 6 && i <= 8)
		e->worldmap[i][j] = 2;
	if (i == 18 && j >= 6 && j <= 18)
		e->worldmap[i][j] = 2;
	if (i == 14 && j >= 6 && j <= 18)
		e->worldmap[i][j] = 2;
	if (j >= 6 && j <= 18 && (j % 2) == 1 && i == 15)
		e->worldmap[i][j] = 2;
	if (j >= 6 && j <= 18 && (j % 2) == 1 && i == 17)
		e->worldmap[i][j] = 2;
	if (i == 13 && j >= 4 && j <= 18 && (j % 2) == 1)
		e->worldmap[i][j] = 2;
	if (i == 12 && j >= 4 && j <= 18 && (j % 2) == 1)
		e->worldmap[i][j] = 2;
}

void	map_init(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < 24)
	{
		y = 0;
		while (y < 24)
		{
			map_put_wall(x, y, e);
			if (x == 11 && y >= 4 && y <= 18 && (y % 2) == 1)
				e->worldmap[x][y] = 2;
			y++;
		}
		x++;
	}
}

int		expose_hook(t_env *e)
{
	ft_bzero(e->str, MAP_H * e->sline);
	wolf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img2, 575, 450);
	mlx_put_image_to_window(e->mlx, e->win, e->img3, MAP_W / 2, MAP_H / 2);
	mlx_put_image_to_window(e->mlx, e->win, e->img4, 30, 650);
	mlx_put_image_to_window(e->mlx, e->win, e->img4, 60, 650);
	mlx_put_image_to_window(e->mlx, e->win, e->img4, 90, 650);
	mlx_put_image_to_window(e->mlx, e->win, e->img4, 120, 650);
	mlx_put_image_to_window(e->mlx, e->win, e->img4, 150, 650);
	mlx_put_image_to_window(e->mlx, e->win, e->img4, 180, 650);
	mlx_put_image_to_window(e->mlx, e->win, e->img6, 15, 15);
	mlx_put_image_to_window(e->mlx, e->win, e->img5, 1200, 515);
	mlx_string_put(e->mlx, e->win, 1200, 600, 0xFFFFFF, e->ammo);
	return (0);
}

void	ft_put_pix_image(t_env *env, int x, int y, int color)
{
	int i;

	i = ((env->bpp / 8) * x) + ((env->sline) * y);
	if (i >= 0 && i < MAP_H * env->sline && i > y * env->sline && i <
		(y * env->sline) + ((env->bpp / 8) * MAP_W))
	{
		env->str[i] = color;
		env->str[i + 1] = (color) >> 8;
		env->str[i + 2] = (color) >> 16;
	}
}

void	verline(int x, t_env *e)
{
	int i;

	i = 0;
	while (i < MAP_H)
	{
		if (e->drawstart <= i && i <= e->drawend)
			ft_put_pix_image(e, x, i, e->color);
		if (i >= e->drawend)
			ft_put_pix_image(e, x, i, 0x808080);
		if (i <= e->drawstart)
			ft_put_pix_image(e, x, i, 0x644300);
		i++;
	}
}
