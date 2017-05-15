/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:57:48 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/14 20:15:20 by lprunier         ###   ########.fr       */
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

int		ft_key_ope(int key, t_map *map)
{
//	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 124 || key == 2)
	{
		ft_clean_image(map->img);
		map->dir += M_PI / 32;
		if (map->dir > 2 * M_PI)
			map->dir = 2 * M_PI - map->dir;
		if (map->sun < -2500)
			map->sun = 2500;
		map->sun -= 80;
		ft_find_point(map->img, map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	}
	else if (key == 123 || key == 0)
	{
		ft_clean_image(map->img);
		map->dir -= M_PI / 32;
		if (map->dir < 0)
			map->dir = 2 * M_PI - map->dir;
		if (map->sun > 2500)
			map->sun = -2500;
		map->sun += 80;
		ft_find_point(map->img, map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	}
	else if (key == 126 || key == 13)
	{
		ft_clean_image(map->img);
		if (map->map[(int)(map->pos_x + 16 * cos(map->dir)) / 64][(int)(map->pos_y - 16 * sin(map->dir)) / 64] != '1')
		{
			map->pos_x = map->pos_x + 16 * cos(map->dir);
			map->pos_y = map->pos_y - 16 * sin(map->dir);
			if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
				ft_up_lvl(map);
		}
		ft_find_point(map->img, map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	}
	else if (key == 125 || key == 1)
	{
		ft_clean_image(map->img);
		if (map->map[(int)(map->pos_x - 16 * cos(map->dir)) / 64][(int)(map->pos_y + 16 * sin(map->dir)) / 64] != '1')
		{
			map->pos_x = map->pos_x - 16 * cos(map->dir);
			map->pos_y = map->pos_y + 16 * sin(map->dir);
			if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
				ft_up_lvl(map);
		}
		ft_find_point(map->img, map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	}
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
	mlx_hook(map->win, 2, 1L << 0, &ft_key_ope, map);
	mlx_loop(map->mlx);
}