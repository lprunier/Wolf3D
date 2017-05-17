/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:43:42 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/16 18:37:35 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "mlx.h"
# include "libft.h"
# include "stdlib.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define V 0
# define F 1
# define W 1280
# define H 800
# define PROJ ((1280 / 2) / tan(M_PI / 6))
# define BLOC 64

typedef struct		s_point
{
	double			x;
	double			y;
	double			h;
}					t_point;

typedef struct		s_img
{
	void			*img;
	char			*cimg;
	int				bpp;
	int				sizel;
	int				endn;
}					t_img;

typedef struct		s_map
{
	char			**map;
	int				width;
	int				height;
	double			pos_x;
	double			pos_y;
	double			dir;
	double			ray;
	int				lvl;
	void			*mlx;
	void			*win;
	int				up;
	int				down;
	float			left;
	float			right;
	int				mouse;
	int				mouse_x;
	int				pause;
	int				wall[64][64];
	int				icon[64][64];
	int				back[1280][800];
	int				sun;
	struct s_img	img;
}					t_map;

/*
**	check.c
*/
int					ft_check_one(t_map *map);
int					ft_check_map(t_map *map);

/*
**	draw.c
*/
void				ft_draw_haut(t_map *map, double haut, int color, int k);
void				ft_reset_screen(t_map *map);
void				ft_find_h(t_map *map, t_point *h);
void				ft_find_v(t_map *map, t_point *h);
int					ft_find_haut(t_map *map, t_point h, t_point v, int *color);
void				ft_find_point(t_map *map);

/*
**	icon.c
*/
void				ft_icon_end(t_map *map);
void				ft_draw_icon(t_map *map);

/*
**	image.c
*/
void				ft_init_img(t_img *img, void *mlx);
void				ft_clean_image(t_img img);
void				ft_ptoi(t_img img, int x, int y, int color);

/*
**	init.c
*/
int					ft_color_wall(t_map *map, int i, int j, int color);
void				ft_color_icon(t_map *map, int i, int j, int color);
void				ft_init_squares(t_map *map);
void				ft_init_map(t_map *map);

/*
**	main.c
*/
char				*ft_join(char *first, char *sec);
int					ft_alloc_map(char *name, t_map *map);

/*
**	play.c
*/
int					ft_error(void);
void				ft_up_lvl(t_map *map);
void				ft_key_right(t_map *map);
void				ft_key_left(t_map *map);
void				ft_key_up(t_map *map);
void				ft_key_down(t_map *map);
int					ft_key_ope(t_map *map);
int					ft_mouse_ope(int x, int y, t_map *map);
int					ft_key(int key, t_map *map);
int					ft_key_hook(int key, t_map *map);
void				ft_menu(t_map *map, int x, int y);
void				ft_pause(t_map *map);
int					ft_mouse_hook(int button, int x, int y, t_map *map);
int					ft_red_cross(t_map *map);
int					ft_key_close(int key, t_map *map);
int					ft_mouse_close(int button, int x, int y, t_map *map);
void				ft_winner(t_map *map);
void				ft_play_game(t_map *map);

/*
**	rand.c
*/
int					ft_rand_brown(void);
int					ft_rand_green_floor(void);
int					ft_rand_green(void);
int					ft_rand_sable(void);

/*
**	wall.c
*/
void				ft_sunset_white(t_map *map, int i, int j);
void				ft_sunset_yellow(t_map *map, int i, int j);
void				ft_sunset_orange(t_map *map, int i, int j);
void				ft_sunset(t_map *map);
void				ft_skybox(t_map *map);

#endif
