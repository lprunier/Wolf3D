/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:57:48 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/15 21:15:23 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>

void	ft_up_lvl(t_map *map)
{
	if (map->lvl == 1)
	{
		if (ft_alloc_map("maps/map_two", map) == V && ft_check_map(map) == V)
			ft_play_game(map);
		else
		{
			miniprintf(2, "Wolf3d: Error Parsing.\n");
			exit(0);
		}
	}
	if (map->lvl == 2)
	{
		if (ft_alloc_map("maps/map_three", map) == V && ft_check_map(map) == V)
			ft_play_game(map);
		else
		{
			miniprintf(2, "Wolf3d: Error Parsing.\n");
			exit(0);
		}
	}
	if (map->lvl == 3)
	{
		if (ft_alloc_map("maps/map_four", map) == V && ft_check_map(map) == V)
			ft_play_game(map);
		else
		{
			miniprintf(2, "Wolf3d: Error Parsing.\n");
			exit(0);
		}
	}
	else if (map->lvl == 4)
	{
		miniprintf(1, "Congrats!\n");
		exit(0);
	}
}

int		ft_key_ope(t_map *map)
{
	if (map->right > 0)
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
	if (map->left > 0)
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
	if (map->up == 1)
	{
		ft_clean_image(map->img);
		if (map->map[(int)(map->pos_x + 16 * cos(map->dir)) / 64][(int)(map->pos_y - 16 * sin(map->dir)) / 64] != '1')
		{
			map->pos_x = map->pos_x + 16 * cos(map->dir);
			map->pos_y = map->pos_y - 16 * sin(map->dir);
			if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
				ft_up_lvl(map);
		}
	}
	if (map->down == 1)
	{
		ft_clean_image(map->img);
		if (map->map[(int)(map->pos_x - 16 * cos(map->dir)) / 64][(int)(map->pos_y + 16 * sin(map->dir)) / 64] != '1')
		{
			map->pos_x = map->pos_x - 16 * cos(map->dir);
			map->pos_y = map->pos_y + 16 * sin(map->dir);
			if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
				ft_up_lvl(map);
		}
	}
	ft_find_point(map->img, map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}

int		ft_mouse_ope(int x, int y, t_map *map)
{
	float div;

	if (y < 0 || y >= H || map->mouse == 0)
	{
		map->right = 0;
		map->left = 0;
		return (0);
	}
	if (x > map->mouse_x)
	{
		div = x - map->mouse_x;
		if (div < W / 2)
			map->right = div / W * (5 * M_PI / 4);
		map->left = 0;
	}
	else if (x < map->mouse_x)
	{
		div = map->mouse_x - x;
		if (div < W / 2)
			map->left = div / W * (5 * M_PI / 4);
		map->right = 0;
	}
	else
	{
		map->left = 0;
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

void	ft_play_game(t_map *map)
{
	t_img	img;

	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, W, H, "Wolf3D");
	ft_init_img(&img, map->mlx);
	map->img = img;
	ft_find_point(map->img, map);
	mlx_put_image_to_window(map->mlx, map->win, img.img, 0, 0);
	mlx_hook(map->win, 2, 1L << 0, ft_key, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_hook(map->win, 6, 1L << 6, ft_mouse_ope, map);
//	mlx_loop_hook(map->mlx, ft_key_ope, map);
	mlx_loop(map->mlx);
}