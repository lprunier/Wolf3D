/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:37:12 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/17 10:41:54 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_key_right(t_map *map)
{
	ft_clean_image(map->img);
	if (map->right == 1)
		map->dir += M_PI / 32;
	else
		map->dir += map->right;
	if (map->dir > 2 * M_PI)
		map->dir = 2 * M_PI - map->dir;
	if (map->right == 1)
		map->right = M_PI / 32;
	map->sun -= map->right / (2 * M_PI) * 6 * W;
	if (map->sun <= -(W * 3))
		map->sun = W * 3;
}

void	ft_key_left(t_map *map)
{
	ft_clean_image(map->img);
	if (map->left == 1)
		map->dir -= M_PI / 32;
	else
		map->dir -= map->left;
	if (map->dir < 0)
		map->dir = 2 * M_PI - map->dir;
	if (map->left == 1)
		map->left = M_PI / 32;
	map->sun += map->left / (2 * M_PI) * 6 * W;
	if (map->sun >= W * 3)
		map->sun = -(W * 3);
}

void	ft_key_up(t_map *map)
{
	ft_clean_image(map->img);
	if (map->map[(int)(map->pos_x + 16 * cos(map->dir)) / 64]
		[(int)(map->pos_y - 16 * sin(map->dir)) / 64] != '1')
	{
		map->pos_x = map->pos_x + 16 * cos(map->dir);
		map->pos_y = map->pos_y - 16 * sin(map->dir);
		if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
			ft_up_lvl(map);
	}
}

void	ft_key_down(t_map *map)
{
	ft_clean_image(map->img);
	if (map->map[(int)(map->pos_x - 16 * cos(map->dir)) / 64]
		[(int)(map->pos_y + 16 * sin(map->dir)) / 64] != '1')
	{
		map->pos_x = map->pos_x - 16 * cos(map->dir);
		map->pos_y = map->pos_y + 16 * sin(map->dir);
		if (map->map[(int)map->pos_x / 64][(int)map->pos_y / 64] == 'F')
			ft_up_lvl(map);
	}
}

int		ft_key_ope(t_map *map)
{
	if (map->pause == 1)
		return (0);
	if (map->right > 0)
		ft_key_right(map);
	if (map->left > 0)
		ft_key_left(map);
	if (map->up == 1)
		ft_key_up(map);
	if (map->down == 1)
		ft_key_down(map);
	ft_find_point(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}
