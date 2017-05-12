/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:05:28 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/11 18:22:37 by lprunier         ###   ########.fr       */
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
	double	haut;
	int	k = 0;

//	map->ray = map->dir - 30;
//	while (map->ray <= map->dir + 30)
	map->ray = M_PI / 4;
	while (map->ray < M_PI * 2)
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
		while (h.x < map->width * 64 && h.y < map->height * 64 && map->map[(int)h.x / 64][(int)h.y / 64] != '1')
		{
		//	printf("h.x=%f\nh.y=%f\nh.x/64=%d\nh.y/64=%d\n\n", h.x, h.y, (int)h.x / 64, (int)h.y / 64);
			h.x += x;
			h.y += y;
		}

//		if (map->ray < M_PI)
//		{
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
/*		}
		else
		{
			if (map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2)
				x = BLOC;
			else
				x = -BLOC;
			y = BLOC * tan(map->ray);
			if (map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2)
				v.x = (int)(map->pos_x / BLOC) * BLOC + BLOC;
			else
				v.x = (int)(map->pos_x / BLOC) * BLOC - 1;
			v.y = map->pos_y + (map->pos_x - v.x) * tan(map->ray);
		}	
*/		while (v.x < map->width * 64 && v.y < map->height * 64 && map->map[(int)v.x / 64][(int)v.y / 64] != '1')
		{
		//	printf("v.x=%f\nv.y=%f\nv.x/64=%d\nv.y/64=%d\n\n", v.x, v.y, (int)v.x / 64, (int)v.y / 64);
			v.x += x;
			v.y += y;
		}

		haut = fabs(map->pos_x - h.x) / cos(map->ray);
		if (haut > fabs(map->pos_x - v.x) / cos(map->ray))
			haut = fabs(map->pos_x - v.x) / cos(map->ray);
	//	if (map->ray >= map->dir)
			haut = haut * cos(-30);
	//	else
	//		haut = haut * cos(M_PI * (30 / 180));
		haut = (BLOC / haut) * 277;

		i = H / 2 - (haut / 2);
		while (i <= H / 2 + (haut / 2))
		{
			ft_ptoi(img, k, i, 0xffff00);
			i++;
		}
		printf("h.x=%d\nh.y=%d\nv.x=%d\nv.y=%d\nhaut=%d\nray=%f\n\n", (int)h.x / 64, (int)h.y / 64, (int)v.x / 64, (int)v.y / 64, (int)haut, map->ray);
//		map->ray += (60.0 / W);
		k++;
		map->ray += M_PI / 2;
	}
}