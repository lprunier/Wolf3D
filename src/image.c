/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:46:57 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/14 14:01:15 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_clean_image(t_img img)
{
	int	i;

	i = -1;
	while (++i < W * H * 4 - 1)
		img.cimg[i] = 0;
}

void	ft_ptoi(t_img img, int x, int y, int color)
{
	int	i;
	int	cp;

	cp = color;
	if (x > (W - 1) || y > (H - 1) || x < 0 || y < 0)
		return ;
	i = x * (img.bpp / 8) + y * img.sizel;
	if (i < 0)
		return ;
	img.cimg[i] = color % 256;
	color /= 256;
	img.cimg[i + 1] = color % 256;
	color /= 256;
	img.cimg[i + 2] = color % 256;
	if (cp == 0xffffff)
		img.cimg[i + 3] = 90;
}