/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:05:28 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/10 18:14:18 by lprunier         ###   ########.fr       */
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

	x = BLOC / atan(map->dir);
	if (map->dir >= 180)
		y = BLOC;
	else
		y = -BLOC;
	if (map->dir >= 180)
		h.y = (int)(map->pos_y / BLOC) * BLOC - 1;
	else
		h.y = (int)(map->pos_y / BLOC) * BLOC + BLOC;
	h.x = map->pos_x + (map->pos_y - h.y) / atan(map->dir);
	while (ft_round(h.x) < W && ft_round(h.y) < H && map->map[ft_round(h.x)][ft_round(h.y)] != '1')
	{
		h.x += x;
		h.y += y;
	}
	h.x = ft_round(h.x);
	h.y = ft_round(h.y);

/*	if (map->dir >= 90 && map->dir < 270)
		x = -BLOC;
	else
		x = BLOC;
	y = BLOC * atan(map->dir);
	if (map->dir >= 90 && map->dir < 270)
		v.x = (int)(map->pos_x / BLOC) * BLOC - 1;
	else
		v.x = (int)(map->pos_x / BLOC) * BLOC + BLOC;
	v.y = map->pos_y + map->pos_x * atan(map->dir);
	while (ft_round(v.x) < W && ft_round(v.y) < H && map->map[ft_round(v.x)][ft_round(v.y)] != '1')
	{
		v.x += x;
		v.y += y;
	}
	v.x = ft_round(v.x);
	v.y = ft_round(v.y);*/

	printf("h.x=%f\nh.y=%f\nv.x=%f\nv->y=%f\n", h.x, h.y, v.x, v.y);
	(void)img;
}