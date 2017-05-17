/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:57:48 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/17 11:06:01 by lprunier         ###   ########.fr       */
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
	{
		map->lvl++;
		ft_play_game(map);
	}
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
	if (map->lvl > 4)
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
