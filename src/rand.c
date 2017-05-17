/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:35:14 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/16 15:39:38 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_rand_brown(void)
{
	int	i;

	i = rand();
	if (i % 10 <= 3)
		return (0x573c28);
	if (i % 10 <= 5)
		return (0x704c35);
	if (i % 10 <= 7)
		return (0x886146);
	if (i % 10 <= 8)
		return (0x5c6265);
	return (0xaa7752);
}

int		ft_rand_sable(void)
{
	int	i;

	i = rand();
	if (i % 10 <= 3)
		return (0xe3dea6);
	if (i % 10 <= 5)
		return (0xcac18a);
	if (i % 10 <= 7)
		return (0xd8d399);
	if (i % 10 <= 8)
		return (0xeae0b2);
	return (0xfdfdd0);
}

int		ft_rand_green(void)
{
	int	i;

	i = rand();
	if (i % 10 <= 5)
		return (0xacd36d);
	if (i % 10 <= 6)
		return (0x8ac459);
	if (i % 10 <= 7)
		return (0xb7d572);
	if (i % 10 <= 8)
		return (0x335d2b);
	return (0x446742);
}

int		ft_rand_green_floor(void)
{
	int	i;

	i = rand();
	if (i % 10 <= 5)
		return (0xacd36d);
	return (0xb7d572);
}
