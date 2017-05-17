/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:57:48 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/16 18:34:49 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_error(void)
{
	miniprintf(2, "Wolf3d: Error Parsing.\n");
	return (0);
}

void	ft_up_lvl(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	free(map->map);
	if (map->lvl == 1)
		(ft_alloc_map("maps/map_two", map) == V && ft_check_map(map) == V)
	? ft_play_game(map) : exit(ft_error());
	if (map->lvl == 2)
		(ft_alloc_map("maps/map_three", map) == V && ft_check_map(map) == V)
	? ft_play_game(map) : exit(ft_error());
	if (map->lvl == 3)
		(ft_alloc_map("maps/map_four", map) == V && ft_check_map(map) == V)
	? ft_play_game(map) : exit(ft_error());
	else if (map->lvl == 4)
		ft_play_game(map);
}

void	ft_key_right(t_map *map)
{
	ft_clean_image(map->img);
	if (map->right == 1)
		map->dir += M_PI / 32;
	else
		map->dir += map->right;
	if (map->dir > 2 * M_PI)
		map->dir = 2 * M_PI - map->dir;
	if (map->right == 1)
		map->right = M_PI / 32;
	map->sun -= map->right / (2 * M_PI) * 6 * W;
	if (map->sun <= -(W * 3))
		map->sun = W * 3;
}

void	ft_key_left(t_map *map)
{
	ft_clean_image(map->img);
	if (map->left == 1)
		map->dir -= M_PI / 32;
	else
		map->dir -= map->left;
	if (map->dir < 0)
		map->dir = 2 * M_PI - map->dir;
	if (map->left == 1)
		map->left = M_PI / 32;
	map->sun += map->left / (2 * M_PI) * 6 * W;
	if (map->sun >= W * 3)
		map->sun = -(W * 3);
}

void	ft_key_up(t_map *map)
{
	ft_clean_image(map->img);
	if (map->map[(int)(map->pos_x + 16 * cos(map->dir)) / 64]
		[(int)(map->pos_y - 16 * sin(map->dir)) / 64] != '1')
	{
		map->pos_x = map->pos_x + 16 * cos(map->dir);
		map->pos_y = map->pos_y - 16 * sin(map->dir);
		if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
			ft_up_lvl(map);
	}
}

void	ft_key_down(t_map *map)
{
	ft_clean_image(map->img);
	if (map->map[(int)(map->pos_x - 16 * cos(map->dir)) / 64]
		[(int)(map->pos_y + 16 * sin(map->dir)) / 64] != '1')
	{
		map->pos_x = map->pos_x - 16 * cos(map->dir);
		map->pos_y = map->pos_y + 16 * sin(map->dir);
		if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
			ft_up_lvl(map);
	}
}

int		ft_key_ope(t_map *map)
{
	if (map->pause == 1)
		return (0);
	if (map->right > 0)
		ft_key_right(map);
	if (map->left > 0)
		ft_key_left(map);
	if (map->up == 1)
		ft_key_up(map);
	if (map->down == 1)
		ft_key_down(map);
	ft_find_point(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}

int		ft_mouse_ope(int x, int y, t_map *map)
{
	float div;

	if (map->pause == 1)
		return (0);
	if (y < 0 || y >= H || map->mouse == 0)
	{
		map->right = 0;
		map->left = 0;
		return (0);
	}
	if (x > map->mouse_x)
	{
		div = x - map->mouse_x;
		(div < W / 2) ? map->right = div / W * (5 * M_PI / 4) : (0);
		map->left = 0;
	}
	else
	{
		div = map->mouse_x - x;
		(div < W / 2) ? map->left = div / W * (5 * M_PI / 4) : (0);
		map->right = 0;
	}
	map->mouse_x = x;
	ft_key_ope(map);
	return (0);
}

int		ft_key(int key, t_map *map)
{
	if (key == 53)
		exit(0);
	if (map->pause == 1)
		return (0);
	if (key == 49 && map->mouse == 0)
	{
		map->mouse = 1;
		map->mouse_x = W / 2;
	}
	else if (key == 49 && map->mouse == 1)
		map->mouse = 0;
	else if (key == 124 || key == 2)
		map->right = 1;
	else if (key == 123 || key == 0)
		map->left = 1;
	else if (key == 126 || key == 13)
		map->up = 1;
	else if (key == 125 || key == 1)
		map->down = 1;
	ft_key_ope(map);
	return (0);
}

int		ft_key_hook(int key, t_map *map)
{
	if (key == 124 || key == 2)
		map->right = 0;
	else if (key == 123 || key == 0)
		map->left = 0;
	else if (key == 126 || key == 13)
		map->up = 0;
	else if (key == 125 || key == 1)
		map->down = 0;
	return (0);
}

void	ft_menu(t_map *map, int x, int y)
{
	if (x >= (W / 8 - 20) && x <= (W / 8 + 60) && y >= 118 && y <= 144)
	{
		map->pos_x = 96;
		map->pos_y = 96;
		map->dir = 6.3 * M_PI / 4;
		map->sun = 0;
		map->pause = 0;
		ft_clean_image(map->img);
		ft_find_point(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	}
	if ((x >= 0 && x < 64 && y >= 0 && y <= 64) || (x > W / 4 && y > H / 4))
	{
		map->pause = 0;
		ft_find_point(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	}
	else if (x >= (W / 8 - 10) && x <= (W / 8 + 50) && y >= 58 && y <= 84)
		exit(0);
}

void	ft_pause(t_map *map)
{
	int	i;

	map->pause = 1;
	i = W / 8 - 10;
	while (i < W / 8 + 50)
	{
		ft_ptoi(map->img, i, 58, 0x876040);
		ft_ptoi(map->img, i, 60, 0x876040);
		ft_ptoi(map->img, i, 82, 0x876040);
		ft_ptoi(map->img, i, 84, 0x876040);
		i++;
	}
	i = W / 8 - 21;
	while (++i < W / 8 + 60)
	{
		ft_ptoi(map->img, i, 118, 0x876040);
		ft_ptoi(map->img, i, 120, 0x876040);
		ft_ptoi(map->img, i, 142, 0x876040);
		ft_ptoi(map->img, i, 144, 0x876040);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	mlx_string_put(map->mlx, map->win, W / 8, 60, 0x876040, "QUIT");
	mlx_string_put(map->mlx, map->win, W / 8 - 15, 120, 0x876040, "RESTART");
}

int		ft_mouse_hook(int button, int x, int y, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	if (button == 1 && x >= 0 && x <= 64 && y >= 0 && y <= 64
		&& map->pause == 0)
	{
		while (++i < W / 4)
		{
			j = -1;
			while (++j < H / 4)
				ft_ptoi(map->img, i, j, map->icon[i % 64][j % 64]);
		}
		i = 23;
		while (++i < 40)
		{
			j = i - 8;
			while (++j < 64 - i + 8)
				ft_ptoi(map->img, i, j, map->wall[i % 64][j % 64]);
		}
		ft_pause(map);
	}
	else if (button == 1 && map->pause == 1)
		ft_menu(map, x, y);
	return (0);
}

int		ft_red_cross(t_map *map)
{
	(void)map;
	exit(0);
	return (0);
}

int		ft_key_close(int key, t_map *map)
{
	if (key == 53)
		exit(0);
	(void)map;
	return (0);
}

int		ft_mouse_close(int button, int x, int y, t_map *map)
{
	if (button == 1 && x >= 17 && x <= 47 && y >= 17 && y <= 47)
		exit(0);
	(void)map;
	return (0);
}

void	ft_winner(t_map *map)
{
	int	i;
	int	j;

	i = 17;
	while (++i < 47)
	{
		j = 17;
		while (++j < 47)
			mlx_pixel_put(map->mlx, map->win, i, j, map->wall[i % 64][j % 64]);
	}
	mlx_string_put(map->mlx, map->win, W / 2 - 30, H / 2 - 10,
		0x876040, "- CONGRATS! -");
	mlx_key_hook(map->win, ft_key_close, map);
	mlx_hook(map->win, 17, (1L << 17), ft_red_cross, map);
	mlx_mouse_hook(map->win, ft_mouse_close, map);
}

void	ft_play_game(t_map *map)
{
	t_img	img;

	if (map->lvl > 1)
		mlx_destroy_window(map->mlx, map->win);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, W, H, "Wolf3D");
	ft_init_img(&img, map->mlx);
	map->img = img;
	ft_find_point(map);
	mlx_put_image_to_window(map->mlx, map->win, img.img, 0, 0);
	if (map->lvl >= 4)
		ft_winner(map);
	else
	{
		mlx_hook(map->win, 2, 1L << 0, ft_key, map);
		mlx_key_hook(map->win, ft_key_hook, map);
		mlx_mouse_hook(map->win, ft_mouse_hook, map);
		mlx_hook(map->win, 6, 1L << 6, ft_mouse_ope, map);
		mlx_hook(map->win, 17, (1L << 17), ft_red_cross, map);
	}
	mlx_loop(map->mlx);
}
