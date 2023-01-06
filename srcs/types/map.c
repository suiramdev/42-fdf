/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 20:21:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/map.h"
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static t_tile	*last_tile(t_tile *tile)
{
	if (tile != NULL)
		while (tile->next != NULL)
			tile = tile->next;
	return (tile);
}

static void	insert_tile(t_map *map, t_vector3 pos)
{
	t_tile	*new;
	t_tile	*last;

	new = malloc(sizeof(t_tile));
	if (new)
	{
		new->pos = pos;
		new->next = NULL;
		last = last_tile(map->data);
		if (last != NULL)
			last->next = new;
		else
			map->data = new;
	}
}

static void	insert_tiles(t_map *map, char *line)
{
	int	i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\n'))
			i++;
		if (line[i])
		{
			j = i;
			while (line[j] && line[j] != ' ' && line[j] != '\n')
				j++;
			count++;
			insert_tile(map, (t_vector3){count, map->height, ft_atoi(ft_substr(line, i, j - i))});
			i = j;
		}
	}
	map->width = count;
	map->height++;
	free(line);
}

t_map	*load_map(char *path)
{
	t_map	*map;
	char	*line;
	int		fd;

	map = malloc(sizeof(t_map));
	if (map)
	{
		map->data = NULL;
		map->height = 0;
		map->width = 0;
		fd = open(path, O_RDONLY);
		while ((line = ft_gnl(fd)) != NULL)
			insert_tiles(map, line);
		close(fd);
	}
	return (map);
}
