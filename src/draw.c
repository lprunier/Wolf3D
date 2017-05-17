/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:05:28 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/17 11:03:49 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_draw_haut(t_map *map, double haut, int color, int k)
{
	int	i;

	if (map->ray > map->dir)
		haut = haut * cos(map->dir - map->ray);
	else
		haut = haut * cos(map->ray - map->dir);
	haut = (BLOC / haut) * PROJ;
	i = H / 2 - (haut / 2);
	while (i <= H / 2 + (haut / 2))
	{
		if (color == 0xffffff)
			ft_ptoi(map->img, k, i, color);
		else
			ft_ptoi(map->img, k, i, map->wall[(int)color % 64]
				[(int)((i - (H / 2 - haut / 2)) / haut * 64)]);
		i++;
	}
	i = H / 2 - (haut / 2) - 1;
	map->ray += ((M_PI / 3) / W);
	if (map->ray > 2 * M_PI)
		map->ray = map->ray - 2 * M_PI;
}

void	ft_find_h(t_map *map, t_point *h)
{
	double	x;
	double	y;

	x = BLOC / (tan(map->ray));
	if (map->ray >= M_PI)
		y = BLOC;
	else
		y = -BLOC;
	if (map->ray <= M_PI)
		h->y = (int)(map->pos_y / BLOC) * BLOC - 1;
	else
		h->y = (int)(map->pos_y / BLOC) * BLOC + BLOC;
	h->x = map->pos_x + (map->pos_y - h->y) / tan(map->ray);
	if (map->ray >= M_PI)
		x = -x;
	while (h->x > 0 && h->y > 0 && h->x / BLOC < map->width &&
		h->y / BLOC < map->height && map->map[(int)(h->x / BLOC)]
		[(int)(h->y / BLOC)] != '1' && map->map[(int)(h->x / BLOC)]
		[(int)(h->y / BLOC)] != 'F')
	{
		h->x += x;
		h->y += y;
	}
}

void	ft_find_v(t_map *map, t_point *v)
{
	double	x;
	double	y;

	if (map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2)
		x = -BLOC;
	else
		x = BLOC;
	y = BLOC * tan(map->ray);
	if (map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2)
		v->x = (int)(map->pos_x / BLOC) * BLOC - 1;
	else
		v->x = (int)(map->pos_x / BLOC) * BLOC + BLOC;
	v->y = map->pos_y + (map->pos_x - v->x) * tan(map->ray);
	if (!(map->ray >= (M_PI / 2) && map->ray < (3 * M_PI) / 2))
		y = -y;
	while (v->x > 0 && v->y > 0 && v->x / BLOC < map->width &&
		v->y / BLOC < map->height && map->map[(int)(v->x / BLOC)]
		[(int)(v->y / BLOC)] != '1')
	{
		v->x += x;
		v->y += y;
	}
}

int		ft_find_haut(t_map *map, t_point h, t_point v, int *color)
{
	int	haut;

	h.h = sqrt(pow((int)h.x - map->pos_x, 2) + pow((int)h.y - map->pos_y, 2));
	v.h = sqrt(pow((int)v.x - map->pos_x, 2) + pow((int)v.y - map->pos_y, 2));
	if (h.h < v.h)
	{
		haut = h.h;
		if (map->map[(int)(h.x / BLOC)][(int)(h.y / BLOC)] == 'F')
			*color = 0xffffff;
		else
			*color = h.x;
	}
	else
	{
		haut = v.h;
		*color = v.y;
	}
	return (haut);
}

void	ft_find_point(t_map *map)
{
	t_point	h;
	t_point	v;
	double	haut;
	int		k;
	int		color;

	k = 0;
	if (map->lvl > 4)
		return (ft_icon_end(map));
	ft_sunset(map);
	ft_reset_screen(map);
	while (k <= W)
	{
		ft_find_h(map, &h);
		ft_find_v(map, &v);
		haut = ft_find_haut(map, h, v, &color);
		ft_draw_haut(map, haut, color, k);
		k++;
	}
	ft_draw_icon(map);
}
