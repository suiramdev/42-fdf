/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 20:56:19 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/map.h"
#include "types/node.h"
#include "types/vector.h"
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	fill_map(t_map *map, char line[READ_SIZE + 1])
{
	int		i;
	int		count;

	i = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\n'))
		{
			if (line[i] == '\n')
			{
				map->width = count;
				count = 0;
				map->height++;
			}
			i++;
		}
		if (line[i])
			insert_node(&map->nodes, new_node(map->nodes, (t_vector3) { count, map->height, ft_atoi(line + i) }));
		count++;
		while (line[i] && line[i] != ' ' && line[i] != '\n')
			i++;
	}
}

t_map	*load_map(char *path)
{
	t_map		*map;
	static char	line[READ_SIZE + 1];
	int			fd;
	int			bytes;

	map = malloc(sizeof(t_map));
	if (map)
	{
		map->nodes = NULL;
		map->height = 0;
		map->width = 0;
		fd = open(path, O_RDONLY);
		while ((bytes = read(fd, line, READ_SIZE)) > 0)
		{
			line[bytes] = '\0'; // safety, not sure that we need it tho
			fill_map(map, line);
		}
		close(fd);
	}
	return (map);
}

int	node_height(t_map *map, t_vector2 from)
{
	t_node	*node;

	node = map->nodes;
	while (node != NULL)
	{
		if (node->pos.x == from.x && node->pos.y == from.y)
			return (node->pos.z);
		node = node->next;
	}
	return (0);
}
