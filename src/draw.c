/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:05:28 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/12 18:21:13 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


#include <stdio.h>

int		ft_round(float x)
{
	int	a;
	int	ret;

	x = x / BLOC;
	a = (int)x;
	if (x < a + 0.5)
		ret = a;
	else
		ret = a + 1;
	return (ret);
}

void	ft_find_point(t_img	img, t_map *map)
{
	t_point	h;
	t_point	v;
	double	x;
	double	y;
	int	i;
	t_point place;
	t_point placet;
	double	haut;
	int	k = 0;
	int	color;

	int	j;
	i = -1;
	while (++i < H / 2)
	{
		j = -1;
		while (++j < W)
			ft_ptoi(img, j, i, 0xccffff);
	}
	while (++i <= H)
	{
		j = -1;
		while (++j < W)
			ft_ptoi(img, j, i, 0x493829);
	}
	printf("Position (%d,%d)\n", (int)(map->pos_x / 64), (int)(map->pos_y / 64));
	map->ray = map->dir - (M_PI / 6);
	while (map->ray <= map->dir + (M_PI / 6))
	{
		x = BLOC / (tan(map->ray));
		if (map->ray >= M_PI)
			y = BLOC;
		else
			y = -BLOC;
		if (map->ray >= M_PI)
			h.y = (int)(map->pos_y / BLOC) * BLOC - 1;
		else
			h.y = (int)(map->pos_y / BLOC) * BLOC + BLOC;
		h.x = map->pos_x + (map->pos_y - h.y) / tan(map->ray);
		if (map->ray >= M_PI)
			x = -x;
		while (h.x > 0 && h.y > 0 && h.x / BLOC < map->width && h.y / BLOC < map->height && map->map[(int)(h.x / BLOC)][(int)(h.y / BLOC)] != '1')
		{
			h.x += x;
			h.y += y;
		}

		if (map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2)
			x = -BLOC;
		else
			x = BLOC;
		y = BLOC * tan(map->ray);
		if (map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2)
			v.x = (int)(map->pos_x / BLOC) * BLOC - 1;
		else
			v.x = (int)(map->pos_x / BLOC) * BLOC + BLOC;
		v.y = map->pos_y + (map->pos_x - v.x) * tan(map->ray);
		if (!(map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2))
			y = -y;
		while (v.x > 0 && v.y > 0 && v.x / BLOC < map->width && v.y / BLOC < map->height && map->map[(int)(v.x / BLOC)][(int)(v.y / BLOC)] != '1')
		{
			v.x += x;
			v.y += y;
		}
		h.h = sqrt(pow(h.x - map->pos_x, 2) + pow(h.y - map->pos_y, 2));
		v.h = sqrt(pow(v.x - map->pos_x, 2) + pow(v.y - map->pos_y, 2));
		place.x = (int)(h.x / 64);
		place.y = (int)(h.y / 64);
		placet.x = (int)(v.x / 64);
		placet.y = (int)(v.y / 64);
		if (place.x > 0 && place.x < map->width - 1 && map->map[(int)place.x - 1][(int)place.y] == '1' && map->map[(int)place.x + 1][(int)place.y] == '1')
		{
			haut = h.h;
			if (h.y < (int)(h.y / 64) * 64 + 32)
				color = 0xffff00;
			else
				color = 0xff00ff;
		}
		else if (place.x >= 0 && place.x < map->width && map->map[(int)placet.x][(int)placet.y - 1] == '1' && map->map[(int)placet.x][(int)placet.y + 1] == '1')
		{
			haut = v.h;
			if (v.x < (int)(v.x / 64) * 64 + 32)
				color = 0x00ffff;
			else
				color = 0x00ff00;
		}
		else if (h.h <= v.h)
		{
			haut = h.h;
			if (h.y < (int)(h.y / 64) * 64 + 32)
				color = 0xffff00;
			else
				color = 0xff00ff;
		}
		else
		{
			haut = v.h;
			if (v.x < (int)(v.x / 64) * 64 + 32)
				color = 0x00ffff;
			else
				color = 0x00ff00;
		}
		if (map->ray > map->dir)
			haut = haut * cos(map->dir - map->ray);
		else
			haut = haut * cos(map->ray - map->dir);
		haut = (BLOC / haut) * PROJ;
		i = H / 2 - (haut / 2);
		while (i <= H / 2 + (haut / 2))
		{
			ft_ptoi(img, k, i, color);
			i++;
		}
		map->ray += ((M_PI / 3) / W);
		k++;
	}
}