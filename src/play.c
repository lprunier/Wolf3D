/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:57:48 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/10 17:06:37 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_play_game(t_map *map)
{
	void	*mlx;
	void	*win;
	t_img	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, W, H, "Wolf3D");
	ft_init_img(&img, mlx);
	ft_find_point(img, map);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}