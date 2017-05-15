/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:44:56 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/14 13:54:05 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_check_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	if (map->width < 3 || map->height < 3)
		return (F);
	if (map->width != map->height)
		return (F);
	if (map->map[1][1] != '0')
		return (F);
	map->pos_x = 96;
	map->pos_y = 96;
	map->dir = (6 * M_PI) / 4;
	while (++i < map->width)
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (F);
	i = 0;
	while (++i < map->height)
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (F);
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			if (map->map[i][j] != '0' && map->map[i][j] != '1' && map->map[i][j] != 'F')
				return (F);
	}
	i = -1;
	miniprintf(1, "w->%d\n", map->width);
	miniprintf(1, "h->%d\n", map->height);
	while (map->map[++i])
		miniprintf(1, "%s\n", map->map[i]);
	return (V);
}