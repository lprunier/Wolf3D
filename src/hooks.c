/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:39:55 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/17 10:40:59 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
