/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:24:34 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:29:51 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_hook5(int keycode, t_env *e)
{
	int i;

	i = 0;
	if (keycode == K_C)
	{
		if (e->jump < 0.69)
		{
			e->jump += 0.20;
			e->jump2 -= 0.20;
			while (i++ < 5)
				key_hook(K_MINUS, e);
		}
	}
	if (keycode == K_Z)
	{
		if (e->jump > 0.51)
		{
			e->jump -= 0.20;
			e->jump2 += 0.20;
			while (i++ < 1)
				key_hook(K_PLUS, e);
		}
	}
}

void	key_hook4(int keycode, t_env *e)
{
	if (keycode == K_ONE)
	{
		e->color1 = 0xCCDDFF;
		e->color2 = 0x222222;
		e->color3 = 0x454545;
		e->color4 = 0xAAAAAA;
	}
	if (keycode == K_TWO)
	{
		e->color1 = 0xFF0000;
		e->color2 = 0x0000FF;
		e->color3 = 0xFFFF00;
		e->color4 = 0x006404;
	}
	if (keycode == K_PLUS)
		if (e->speed < 0.4)
			e->speed += 0.1;
	if (keycode == K_MINUS)
		if (e->speed > 0.1)
			e->speed -= 0.1;
}

void	key_hook3(int keycode, t_env *e)
{
	if (keycode == K_DOWN || keycode == K_S)
	{
		if (e->worldmap[(int)(e->posx - e->diry)][(int)e->posy] == 0)
			e->posx -= e->dirx * e->speed;
		if (e->worldmap[(int)e->posx][(int)(e->posy - e->diry)] == 0)
			e->posy -= e->diry * e->speed;
	}
	if (keycode == K_LEFT || keycode == K_A)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(e->speed) - e->diry * sin(e->speed);
		e->diry = e->olddirx * sin(e->speed) + e->diry * cos(e->speed);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(e->speed) - e->planey * sin(e->speed);
		e->planey = e->oldplanex * sin(e->speed) + e->planey * cos(e->speed);
	}
	if (keycode == K_RIGHT || keycode == K_D)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(-e->speed) - e->diry * sin(-e->speed);
		e->diry = e->olddirx * sin(-e->speed) + e->diry * cos(-e->speed);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(-e->speed) - e->planey * sin(-e->speed);
		e->planey = e->oldplanex * sin(-e->speed) + e->planey * cos(-e->speed);
	}
}

void	key_hook2(int keycode, t_env *e)
{
	if (keycode == K_Q)
	{
		if (e->worldmap[(int)(e->posx - e->planex)][(int)e->posy] == 0)
			e->posx -= e->planex * e->speed;
		if (e->worldmap[(int)e->posx][(int)(e->posy - e->planey)] == 0)
			e->posy -= e->planey * e->speed;
	}
	if (keycode == K_E)
	{
		if (e->worldmap[(int)(e->posx + e->planex)][(int)e->posy] == 0)
			e->posx += e->planex * e->speed;
		if (e->worldmap[(int)(e->posx)][(int)(e->posy + e->planey)] == 0)
			e->posy += e->planey * e->speed;
	}
	if (keycode == K_UP || keycode == K_W)
	{
		if (e->worldmap[(int)(e->posx + e->dirx)][(int)e->posy] == 0)
			e->posx += e->dirx * e->speed;
		if (e->worldmap[(int)e->posx][(int)(e->posy + e->diry)] == 0)
			e->posy += e->diry * e->speed;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		exit(0);
	if (keycode == K_P_UP && e->rotupdown <= 2.1)
		e->rotupdown += 0.1;
	if (keycode == K_P_DOWN && e->rotupdown >= 0)
		e->rotupdown -= 0.1;
	if (keycode == K_SPACE)
		ammo_shot(e);
	if (keycode == K_R)
	{
		e->ammo[0] = '4';
		e->ammo[1] = '2';
		e->ammo[2] = '\0';
	}
	key_hook2(keycode, e);
	key_hook3(keycode, e);
	key_hook4(keycode, e);
	key_hook5(keycode, e);
	expose_hook(e);
	return (0);
}
