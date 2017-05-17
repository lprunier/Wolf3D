/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:59:34 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/16 15:21:39 by lprunier         ###   ########.fr       */
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

int		ft_alloc_map(char *name, t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;

	map->width = 0;
	map->height = 0;
	map->lvl++;
	tmp = ft_strdup("\0");
	if ((fd = open(name, O_RDONLY)) < 0)
		return (F);
	while (get_next_line(fd, &line))
	{
		if (map->width != 0 && map->width != (int)ft_strlen(line))
		{
			free(tmp);
			return (F);
		}
		(map->width == 0) ? map->width = ft_strlen(line) : (0);
		tmp = ft_join(tmp, line);
		map->height++;
	}
	map->map = ft_strsplit(tmp, ' ');
	free(tmp);
	close(fd);
	return (V);
}

int		main(int ac, char **av)
{
	t_map	map;

	ft_init_map(&map);
	if (ac == 1)
	{
		if (ft_alloc_map("maps/map_one", &map) == V && ft_check_map(&map) == V)
		{
			ft_skybox(&map);
			ft_init_squares(&map);
			ft_play_game(&map);
		}
		else
			miniprintf(2, "Wolf3d: Error Parsing.\n");
	}
	else
		miniprintf(1, "%s: Wolf3d only run with predefined maps.\n", av[1]);
	return (0);
}
