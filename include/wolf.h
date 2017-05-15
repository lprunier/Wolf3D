/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:43:42 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/14 17:53:23 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
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

typedef struct	s_point
{
	double		x;
	double		y;
	double		h;
}				t_point;

typedef struct	s_img
{
	void		*img;
	char		*cimg;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
	double		pos_x;
	double		pos_y;
	double		dir;
	double		ray;
	int			lvl;
	void		*mlx;
	void		*win;
	int			wall[64][64];
	int			icon[64][64];
	int			back[1280][800];
	struct s_img	img;
}				t_map;

/*
*	check.c
*/
int		ft_check_map(t_map *map);

/*
*	draw.c
*/
int		ft_round(float x);
void	ft_find_point(t_img	img, t_map *map);

/*
*	image.c
*/
void	ft_clean_image(t_img img);
void	ft_ptoi(t_img img, int x, int y, int color);

/*
*	init.c
*/
void	ft_init_img(t_img *img, void *mlx);

/*
*	main.c
*/
char	*ft_join(char *first, char *sec);
int		ft_alloc_map(char *name, t_map *map);

/*
*	play.c
*/
int		ft_key_ope(int key, t_map *map);
void	ft_play_game(t_map *map);

/*
*	wall.c
*/
int		ft_rand_brown();
int		ft_rand_green_floor();
int		ft_rand_green();
int		ft_rand_blue();
int		ft_rand_sable();
void	ft_skybox(t_map map);

#endif