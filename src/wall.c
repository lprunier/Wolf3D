/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:43:02 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/14 18:03:44 by lprunier         ###   ########.fr       */
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

void	ft_skybox(t_map map)
{
	int	i;
	int	j;
//	int	color;

	i = 0;
	printf("%d\n", __LINE__);
	while (i < W)
	{
		j = 0;
		while (j < H)
		{
			map.back[i][j] = 0x888800;
			j++;
		}
		i++;
	}
	// while (i < H / 2)
	// {
	// 	j = 0;
	// 	color = ft_rand_blue();
	// 	while (j < W)
	// 	{
	// 		map.back[j][i] = color;
	// 		map.back[j][i + 1] = color;
	// 		j++;
	// 		if (j % 8 == 0)
	// 			color = ft_rand_blue();
	// 	}
	// 	i += 8;
	// }
/*	while ( < H)
	{
		j = 0;
		color = ft_rand_green_floor();
		while (j < W)
		{
			map.back[i][j] = color;
			map.back[i + 1][j] = color;
			map.back[i + 2][j] = color;
			map.back[i + 3][j] = color;
			map.back[i + 4][j] = color;
			map.back[i + 5][j] = color;
			map.back[i + 6][j] = color;
			map.back[i + 7][j] = color;
			j++;
			if (j % 8 == 0)
				color = ft_rand_green_floor();
		}
		i += 8;
	}*/
}





