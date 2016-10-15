/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:24:51 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 15:16:36 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ammo_shot(t_env *e)
{
	int		tmp;
	int		rdm;
	char	*test;

	tmp = ft_atoi(e->ammo);
	tmp--;
	if (tmp < 0)
		tmp = 0;
	test = ft_itoa(tmp);
	if (tmp > 0)
	{
		rdm = rand() % 3;
		if (rdm == 0)
			key_hook(K_P_UP, e);
		else if (rdm == 1)
			key_hook(K_P_DOWN, e);
		else if (rdm == 2)
			key_hook(K_A, e);
		else if (rdm == 3)
			key_hook(K_D, e);
	}
	ft_strcpy(e->ammo, test);
	free(test);
}

void		init_var(t_env *e)
{
	map_init(e);
	e->i = 0;
	e->posx = 20;
	e->posy = 20;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->speed = 0.15;
	e->rotupdown = 1;
	e->jump = 0.5;
	e->jump2 = 0.5;
	e->color1 = 0xDE3163;
	e->color2 = 0x0f497b;
	e->color3 = 0x60b644;
	e->color4 = 0xcccc66;
	e->ammo[0] = '4';
	e->ammo[1] = '2';
	e->ammo[2] = '\0';
}

int			main(void)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		return (-1);
	e.win = mlx_new_window(e.mlx, MAP_W, MAP_H, "wolf3D");
	if (!(e.img = mlx_new_image(e.mlx, MAP_W, MAP_H)))
		return (-1);
	if (!(e.str = mlx_get_data_addr(e.img, &e.bpp, &e.sline, &e.endian)))
		return (-1);
	init_var(&e);
	ft_mlx_gun(&e);
	ft_mlx_cursor(&e);
	ft_mlx_heart(&e);
	ft_mlx_ammo(&e);
	ft_mlx_map(&e);
	wolf(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
	close(e.fd);
	return (0);
}
