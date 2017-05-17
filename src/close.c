/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:33:58 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/17 10:42:01 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
