/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:43:02 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/14 20:11:36 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>

int		ft_rand_brown()
{
	int	i;

	i = rand();
	if (i % 10 <= 3)
		return (0x573c28);
	if (i % 10 <= 5)
		return (0x704c35);
	if (i % 10 <= 7)
		return (0x886146);
	if (i % 10 <= 8)
		return (0x5c6265);
	return (0xaa7752);
}

int		ft_rand_sable()
{
	int	i;

	i = rand();
	if (i % 10 <= 3)
		return (0xe3dea6);
	if (i % 10 <= 5)
		return (0xcac18a);
	if (i % 10 <= 7)
		return (0xd8d399);
	if (i % 10 <= 8)
		return (0xeae0b2);
	return (0xfdfdd0);
}

int		ft_rand_green()
{
	int	i;

	i = rand();
	if (i % 10 <= 5)
		return (0xacd36d);
	if (i % 10 <= 6)
		return (0x8ac459);
	if (i % 10 <= 7)
		return (0xb7d572);
	if (i % 10 <= 8)
		return (0x335d2b);
	return (0x446742);
}

int		ft_rand_green_floor()
{
	int	i;

	i = rand();
	if (i % 10 <= 5)
		return (0xacd36d);
	return (0xb7d572);
}

int		ft_rand_blue()
{
	int	i;

	i = rand();
	if (i % 10 <= 7)
		return (0x7eabff);
	return (0x9aa9f9);
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
	i = 575 + map->sun;
	while (++i < (705 + map->sun))
	{
		j = 325;
		while (++j < H / 2)
			if (i >= 0 && j >= 0 && i < W && j < H)
				map->back[i][j] = 0xffffdd;
	}
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





