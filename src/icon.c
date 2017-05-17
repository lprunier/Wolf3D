/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icon.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:54:11 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/17 11:03:35 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_icon_end(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < W)
	{
		j = 0;
		while (j < H)
		{
			ft_ptoi(map->img, i, j, 0);
			ft_ptoi(map->img, i, j, map->icon[i % 64][j % 64]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return ;
}

void	ft_draw_icon(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
			ft_ptoi(map->img, i, j, map->icon[i][j]);
	}
	i = 15;
	while (i < 64 - 15)
	{
		ft_ptoi(map->img, 24, i, map->wall[24 % 64][i % 64]);
		ft_ptoi(map->img, 25, i, map->wall[25 % 64][i % 64]);
		ft_ptoi(map->img, 26, i, map->wall[26 % 64][i % 64]);
		ft_ptoi(map->img, 27, i, map->wall[27 % 64][i % 64]);
		ft_ptoi(map->img, 36, i, map->wall[36 % 64][i % 64]);
		ft_ptoi(map->img, 37, i, map->wall[37 % 64][i % 64]);
		ft_ptoi(map->img, 38, i, map->wall[38 % 64][i % 64]);
		ft_ptoi(map->img, 39, i, map->wall[39 % 64][i % 64]);
		i++;
	}
}
