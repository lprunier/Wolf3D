/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:43:02 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/16 16:44:47 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_sunset_white(t_map *map, int i, int j)
{
	i = 575 + map->sun;
	while (++i < (705 + map->sun))
	{
		j = 325;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xffffdd;
	}
}

void	ft_sunset_yellow(t_map *map, int i, int j)
{
	while (++i < (760 + map->sun))
	{
		j = 270;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xf67e44;
	}
	i = 535 + map->sun;
	while (++i < (745 + map->sun))
	{
		j = 285;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xfabf61;
	}
	i = 550 + map->sun;
	while (++i < (730 + map->sun))
	{
		j = 300;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xffffe2;
	}
	ft_sunset_white(map, i, j);
}

void	ft_sunset_orange(t_map *map, int i, int j)
{
	while (++i < (830 + map->sun))
	{
		j = 200;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0x815051;
	}
	i = 475 + map->sun;
	while (++i < (805 + map->sun))
	{
		j = 225;
		while (++j < (H / 2))
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xa95745;
	}
	i = 500 + map->sun;
	while (++i < (780 + map->sun))
	{
		j = 250;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xd66840;
	}
	i = 520 + map->sun;
	ft_sunset_yellow(map, i, j);
}

void	ft_sunset(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < H / 2)
	{
		j = -1;
		while (++j < W)
			map->back[j][i] = 0x3f3f63;
		i++;
	}
	i = 400 + map->sun;
	while (++i < (880 + map->sun))
	{
		j = 150;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0x674d5c;
	}
	i = 450 + map->sun;
	ft_sunset_orange(map, i, j);
}

void	ft_skybox(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < H / 2)
	{
		j = -1;
		while (++j < W)
			map->back[j][i] = 0x3f3f63;
		i++;
	}
	while (i < H)
	{
		j = -1;
		while (++j < W)
			map->back[j][i] = 0xacd36d;
		i++;
	}
}
