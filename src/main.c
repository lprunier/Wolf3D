/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:59:34 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/15 15:27:41 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#include <stdio.h>

char	*ft_join(char *first, char *sec)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(first, " ");
	free(first);
	ret = ft_strjoin(tmp, sec);
	free(sec);
	free(tmp);
	return (ret);
}

int	ft_alloc_map(char *name, t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;

	map->width = 0;
	map->lvl++;
	map->height = 0;
	map->map = NULL;
	tmp = ft_strdup("\0");
	if (!(fd = open(name, O_RDONLY)))
		return (F);
	while (get_next_line(fd, &line))
	{
		if (map->width != 0 && map->width != (int)ft_strlen(line))
		{
			free(tmp);
			return (F);
		}
		else
			map->width = ft_strlen(line);
		tmp = ft_join(tmp, line);
		map->height++;
	}
	map->map = ft_strsplit(tmp, ' ');
	free(tmp);
	close(fd);
	return (V);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		i;
	int		j;
	int		color;
	int		icon;
	int		tmp;
	int		k;

	map.lvl = 0;
	map.sun = 0;
	map.up = 0;
	map.down = 0;
	map.left = 0;
	map.right = 0;
	map.mouse = 0;
	map.mouse_x = W / 2;
	if (ac == 1)
	{
		if (ft_alloc_map("maps/map_one", &map) == V && ft_check_map(&map) == V)
		{
			i = 0;
			ft_skybox(&map);
			while (i < 64)
			{
				j = -1;
				color = ft_rand_brown();
				icon = ft_rand_sable();
				while (++j < 64)
				{
					map.wall[i][j] = color;
					map.wall[i + 1][j] = color;
					map.wall[i + 2][j] = color;
					map.wall[i + 3][j] = color;
					map.icon[i][j] = icon;
					map.icon[i + 1][j] = icon;
					map.icon[i + 2][j] = icon;
					map.icon[i + 3][j] = icon;
					if (j % 4 == 0)
					{
						color = ft_rand_brown();
						icon = ft_rand_sable();
					}
				}
				k = -1;
				tmp = 2 + rand() % 10;
				color = ft_rand_green();
				while (++k < tmp)
				{
					map.wall[i][k] = color;
					map.wall[i + 1][k] = color;
					map.wall[i + 2][k] = color;
					map.wall[i + 3][k] = color;
					if (k % 4 == 0)
						color = ft_rand_green();
				}
				i += 4;
			}
			ft_play_game(&map);
		}
		else
			miniprintf(2, "Wolf3d: Error Parsing.\n");
	}
	else
	{
		miniprintf(1, "lancement map %s.\n", av[1]);
	}
	return (0);
}