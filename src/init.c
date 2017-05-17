/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:39:59 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/16 15:33:00 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_color_wall(t_map *map, int i, int j, int color)
{
	map->wall[i][j] = color;
	map->wall[i + 1][j] = color;
	map->wall[i + 2][j] = color;
	map->wall[i + 3][j] = color;
	if (j % 4 == 0)
		color = ft_rand_green();
	return (color);
}

void	ft_color_icon(t_map *map, int i, int j, int color)
{
	map->icon[i][j] = color;
	map->icon[i + 1][j] = color;
	map->icon[i + 2][j] = color;
	map->icon[i + 3][j] = color;
}

void	ft_init_squares(t_map *map)
{
	int		i;
	int		j;
	int		color;
	int		icon;

	i = 0;
	while (i < 64)
	{
		j = -1;
		color = ft_rand_brown();
		icon = ft_rand_sable();
		while (++j < 64)
		{
			ft_color_wall(map, i, j, color);
			ft_color_icon(map, i, j, icon);
			(j % 4 == 0) ? color = ft_rand_brown() : (0);
			(j % 4 == 0) ? icon = ft_rand_sable() : (0);
		}
		j = -1;
		icon = 2 + rand() % 10;
		color = ft_rand_green();
		while (++j < icon)
			color = ft_color_wall(map, i, j, color);
		i += 4;
	}
}

void	ft_init_map(t_map *map)
{
	map->lvl = 0;
	map->sun = 0;
	map->up = 0;
	map->down = 0;
	map->left = 0;
	map->right = 0;
	map->mouse = 0;
	map->mouse_x = W / 2;
	map->pause = 0;
}
