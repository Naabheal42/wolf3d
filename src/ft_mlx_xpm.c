/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:17:01 by nbrizini          #+#    #+#             */
/*   Updated: 2016/05/03 16:59:27 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				ft_mlx_gun(t_env *e)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	if (!(e->img2 = mlx_xpm_file_to_image(e->mlx, "xpmImg/gun.xpm", &x, &y)))
		exit(0);
	if (!(e->str2 = mlx_get_data_addr(e->img2, &(e->bpp),
		&(e->sline2), &(e->endian))))
		exit(0);
}

void				ft_mlx_cursor(t_env *e)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	if (!(e->img3 = mlx_xpm_file_to_image(e->mlx, "xpmImg/cursor.xpm", &x, &y)))
		exit(0);
	if (!(e->str3 = mlx_get_data_addr(e->img3, &(e->bpp),
		&(e->sline3), &(e->endian))))
		exit(0);
}

void				ft_mlx_heart(t_env *e)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	if (!(e->img4 = mlx_xpm_file_to_image(e->mlx, "xpmImg/heart.xpm", &x, &y)))
		exit(0);
	if (!(e->str4 = mlx_get_data_addr(e->img4, &(e->bpp),
		&(e->sline4), &(e->endian))))
		exit(0);
}

void				ft_mlx_ammo(t_env *e)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	if (!(e->img5 = mlx_xpm_file_to_image(e->mlx,
		"xpmImg/ammo_box.xpm", &x, &y)))
		exit(0);
	if (!(e->str5 = mlx_get_data_addr(e->img5, &(e->bpp),
		&(e->sline5), &(e->endian))))
		exit(0);
}

void				ft_mlx_map(t_env *e)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	if (!(e->img6 = mlx_xpm_file_to_image(e->mlx, "xpmImg/map.xpm", &x, &y)))
		exit(0);
	if (!(e->str6 = mlx_get_data_addr(e->img6, &(e->bpp),
		&(e->sline6), &(e->endian))))
		exit(0);
}
