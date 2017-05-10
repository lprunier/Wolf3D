/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:43:42 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/09 17:22:09 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"

# define W 1100
# define H 700

typedef struct	s_img
{
	void		*img;
	char		*cimg;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

/*
*	image.c
*/
void	ft_ptoi(t_img img, int x, int y, int color);

/*
*	init.c
*/
void	ft_init_img(t_img *img, void *mlx);

/*
*	play.c
*/
void	ft_play_game(void);

#endif