/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:05:28 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/15 14:08:00 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


#include <stdio.h>

int		ft_round(float x)
{
	int	a;
	int	ret;

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
	double	haut;
	int	k = 0;
	int	color;
//	int	green;
//	int	blue;
	int	j;

	i = -1;
	ft_sunset(map);
	while (++i < W)
	{
		j = -1;
		while (++j < H)
			ft_ptoi(img, i, j, map->back[i][j]);
	}
	map->ray = map->dir - (M_PI / 6);
	if (map->ray < 0)
		map->ray = 2 * M_PI + map->ray;
	while (k <= W)
	{
		x = BLOC / (tan(map->ray));
		if (map->ray >= M_PI)
			y = BLOC;
		else
			y = -BLOC;
		if (map->ray <= M_PI)
			h.y = (int)(map->pos_y / BLOC) * BLOC - 1;
		else
			h.y = (int)(map->pos_y / BLOC) * BLOC + BLOC;
		h.x = map->pos_x + (map->pos_y - h.y) / tan(map->ray);
		if (map->ray >= M_PI)
			x = -x;
		while (h.x > 0 && h.y > 0 && h.x / BLOC < map->width && h.y / BLOC < map->height && map->map[(int)(h.x / BLOC)][(int)(h.y / BLOC)] != '1' && map->map[(int)(h.x / BLOC)][(int)(h.y / BLOC)] != 'F')
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
		h.h = sqrt(pow((int)h.x - map->pos_x, 2) + pow((int)h.y - map->pos_y, 2));
		v.h = sqrt(pow((int)v.x - map->pos_x, 2) + pow((int)v.y - map->pos_y, 2));
		if (h.h < v.h)
		{
			haut = h.h;
			if (map->map[(int)(h.x / BLOC)][(int)(h.y / BLOC)] == 'F')
				color = 0xffffff;
			else
				color = 'h';
		}
		else
		{
			haut = v.h;
			color = 'v';
		}
		if (map->ray > map->dir)
			haut = haut * cos(map->dir - map->ray);
		else
			haut = haut * cos(map->ray - map->dir);
		haut = (BLOC / haut) * PROJ;
		// if (map->lvl % 2 == 1 && color != 0xffffff)
		// 	color = 0xff;
		// ft_draw_wall(haut, color, k, img);
		i = H / 2 - (haut / 2);
		while (i <= H / 2 + (haut / 2))
		{
			if (color == 0xffffff)
				ft_ptoi(img, k, i, color);
			else if (color == 'v')
				ft_ptoi(img, k, i, map->wall[(int)v.y % 64][(int)((i - (H / 2 - haut / 2)) / haut * 64)]);
			else
				ft_ptoi(img, k, i, map->wall[(int)h.x % 64][(int)((i - (H / 2 - haut / 2)) / haut * 64)]);
			i++;
		}
		i = H / 2 - (haut / 2) - 1;
		map->ray += ((M_PI / 3) / W);
		if (map->ray > 2 * M_PI)
			map->ray = map->ray - 2 * M_PI;
		k++;
	}
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			ft_ptoi(img, i, j, map->icon[i][j]);
		}
	}
//	printf("oui\n");
}