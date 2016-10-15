/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:45:11 by nbrizini          #+#    #+#             */
/*   Updated: 2016/10/15 17:33:39 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define W 24
# define H 24
# define MAP_W 1280
# define MAP_H 720
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define M_LEFT 		1
# define M_RIGHT 		2
# define M_SCROLL		3
# define M_S_UP			4
# define M_S_DOWN		5
# define M_S_LEFT		6
# define M_S_RIGHT		7

# define K_ESC		53
# define K_ENTER 	36
# define K_SPACE 	49
# define K_P_UP 	116
# define K_P_DOWN	121

# define K_PLUS		69
# define K_MINUS	78

# define K_UP		126
# define K_DOWN		125
# define K_LEFT		123
# define K_RIGHT	124

# define K_NUM_ZERO 	82
# define K_NUM_ONE		83
# define K_NUM_TWO		84
# define K_NUM_THREE	85
# define K_NUM_FOUR		86
# define K_NUM_FIVE		87
# define K_NUM_SIX		88
# define K_NUM_SEVEN	89
# define K_NUM_EIGHT	91
# define K_NUM_NINE		92

# define K_ZERO 	29
# define K_ONE		18
# define K_TWO		19
# define K_THREE	20
# define K_FOUR		21
# define K_FIVE		23
# define K_SIX		22
# define K_SEVEN	26
# define K_EIGHT	28
# define K_NINE		25

# define K_A 		0
# define K_B		11
# define K_C 		8
# define K_D 		2
# define K_E 		14
# define K_F 		3
# define K_G 		5
# define K_H 		4
# define K_I 		34
# define K_J 		38
# define K_K 		40
# define K_L 		37
# define K_M 		46
# define K_N 		45
# define K_O 		31
# define K_P 		35
# define K_Q 		12
# define K_R 		15
# define K_S 		1
# define K_T 		17
# define K_U 		32
# define K_V 		9
# define K_W		13
# define K_X 		7
# define K_Y 		16
# define K_Z 		6

typedef struct			s_env
{
	double				olddirx;
	double				oldplanex;
	int					worldmap[24][24];
	double				rotupdown;
	void				*win;
	void				*mlx;
	char				*str;
	void				*img;
	int					bpp;
	int					sline;
	int					endian;
	char				**split;
	double				posx;
	double				speed;
	int					color1;
	int					color2;
	int					color3;
	int					color4;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					color;
	int					i;
	int					j;
	int					k;
	int					fd;
	char				*line;
	float				jump;
	float				jump2;
	char				*str2;
	void				*img2;
	int					sline2;
	char				*str3;
	void				*img3;
	int					sline3;
	char				*str4;
	void				*img4;
	int					sline4;
	char				*str5;
	void				*img5;
	int					sline5;
	char				*str6;
	void				*img6;
	int					sline6;
	char				ammo[3];
}						t_env;

int						expose_hook(t_env *e);
void					ft_put_pix_image(t_env *env, int x, int y, int color);
void					verline(int x, t_env *e);
void					init_var(t_env *e);
void					ammo_shot(t_env *e);
void					key_hook5(int keycode, t_env *e);
void					key_hook4(int keycode, t_env *e);
void					key_hook3(int keycode, t_env *e);
void					key_hook2(int keycode, t_env *e);
int						key_hook(int keycode, t_env *e);
void					map_init(t_env *e);
void					map_put_wall(int i, int j, t_env *e);
void					wolf4(t_env *e);
void					wolf2(t_env *e);
void					wolf3(t_env *e);
void					wolf1(t_env *e, int x);
int						wolf(t_env *e);
void					ft_mlx_heart(t_env *e);
void					ft_mlx_ammo(t_env *e);
void					ft_mlx_map(t_env *e);
void					ft_mlx_gun(t_env *e);
void					ft_mlx_cursor(t_env *e);

#endif
