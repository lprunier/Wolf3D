/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <lprunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:59:34 by lprunier          #+#    #+#             */
/*   Updated: 2017/05/10 17:04:56 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

	if (ac == 1)
	{
		if (ft_alloc_map("maps/map_one", &map) == V && ft_check_map(&map) == V)
			ft_play_game(&map);
		else
			miniprintf(2, "Wolf3d: Error Parsing.\n");
	}
	else
	{
		miniprintf(1, "lancement map %s.\n", av[1]);
	}
	return (0);
}