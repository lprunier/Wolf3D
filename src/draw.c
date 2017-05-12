/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:05:28 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/12 12:04:10 by lprunier         ###   ########.fr       */
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

	map->ray = map->dir - (M_PI / 6);
//	printf("map->ray=%f\n", map->ray);
	while (map->ray <= map->dir + (M_PI / 6))
//	map->ray = M_PI / 4;
//	while (map->ray < 2 * M_PI)
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
		while (h.x > 0 && h.y > 0 && (int)h.x / BLOC < map->width && (int)h.y / BLOC < map->height && map->map[(int)h.x / BLOC][(int)h.y / BLOC] != '1')
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
		while (v.x > 0 && v.y > 0 && (int)v.x / BLOC < map->width && (int)v.y / BLOC < map->height && map->map[(int)v.x / BLOC][(int)v.y / BLOC] != '1')
		{
			v.x += x;
			v.y += y;
		}

		haut = fabs(map->pos_x - h.x) / fabs(cos(map->ray));
	//	printf("%d->%d | map->ray=%f\n", __LINE__, (int)haut, map->ray);
		if (haut > fabs(map->pos_x - v.x) / fabs(cos(map->ray)))
			haut = fabs(map->pos_x - v.x) / fabs(cos(map->ray));
	//	printf("%d->%d\n", __LINE__, (int)haut);
		if (map->ray <= map->dir)
			haut = haut * cos(-(M_PI / 6));
		else
			haut = haut * cos(M_PI / 6);
	//	printf("%d->%d\n", __LINE__, (int)haut);
		haut = (BLOC / haut) * PROJ;
	//	printf("h(%d,%d) | v(%d,%d) | %d\n\n", (int)h.x / 64, (int)h.y / 64, (int)v.x / 64, (int)v.y / 64, (int)haut);
		i = H / 2 - (haut / 2);
		while (i <= H / 2 + (haut / 2))
		{
			ft_ptoi(img, k, i, 0xffff00);
			i++;
		}
		map->ray += ((M_PI / 3) / W);
	//	map->ray += M_PI / 2;
		k++;
	}
}