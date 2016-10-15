/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:25:08 by nbrizini          #+#    #+#             */
/*   Updated: 2016/02/25 16:25:09 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf4(t_env *e)
{
	if (e->side == 0)
	{
		if (e->stepx <= 0)
			e->color = e->color1;
		else
			e->color = e->color2;
	}
	else
	{
		if (e->stepy <= 0)
			e->color = e->color3;
		else
			e->color = e->color4;
	}
}

void	wolf2(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] > 0)
			e->hit = 1;
	}
}

void	wolf3(t_env *e)
{
	if (e->side == 0)
		e->perpwalldist = fabs((e->mapx - e->rayposx + (1 - e->stepx) * 0.5)
				/ e->raydirx);
	else
		e->perpwalldist = fabs((e->mapy - e->rayposy + (1 - e->stepy) * 0.5)
				/ e->raydiry);
	e->lineheight = abs((int)(MAP_H / e->perpwalldist));
	e->drawstart = (-e->lineheight * e->jump) + (MAP_H * 0.5) * e->rotupdown;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = (e->lineheight * e->jump2) + (MAP_H * 0.5) * e->rotupdown;
	if (e->drawend >= MAP_H)
		e->drawend = MAP_H - 1;
}

void	wolf1(t_env *e, int x)
{
	e->camerax = 2 * x / (double)MAP_W - 1;
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->raydirx = e->dirx + e->planex * e->camerax;
	e->raydiry = e->diry + e->planey * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) /
			(e->raydirx * e->raydirx));
	e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) /
			(e->raydiry * e->raydiry));
	e->hit = 0;
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
}

int		wolf(t_env *e)
{
	int	x;

	x = 0;
	while (x < MAP_W)
	{
		wolf1(e, x);
		if (e->raydiry < 0)
		{
			e->stepy = -1;
			e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
		}
		else
		{
			e->stepy = 1;
			e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
		}
		wolf2(e);
		wolf3(e);
		wolf4(e);
		verline(x, e);
		x++;
	}
	return (0);
}
