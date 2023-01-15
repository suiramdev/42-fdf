/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2023/01/15 17:41:06 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/map.h"
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static t_node	*last_node(t_node *node)
{
	if (node != NULL)
		while (node->next != NULL)
			node = node->next;
	return (node);
}

static void	insert_node(t_map *map, t_vector3 pos)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (new)
	{
		new->pos = pos;
		new->next = NULL;
		last = last_node(map->nodes);
		if (last != NULL)
			last->next = new;
		else
			map->nodes = new;
	}
}

static void	fill_map(t_map *map, char *line)
{
	int	i;
	int j;

	i = 0;
	map->width = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\n'))
			i++;
		if (line[i])
		{
			j = i;
			while (line[j] && line[j] != ' ' && line[j] != '\n')
				j++;
			insert_node(map, (t_vector3) { map->width, map->height, ft_atoi(ft_substr(line, i, j - i))});
			map->width++;
			i = j;
		}
	}
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
		map->nodes = NULL;
		map->height = 0;
		map->width = 0;
		fd = open(path, O_RDONLY);
		while ((line = ft_gnl(fd)) != NULL)
			fill_map(map, line);
		close(fd);
	}
	return (map);
}

int	node_height(t_map *map, t_vector2 from)
{
	t_node		*node;

	node = map->nodes;
	while (node != NULL)
	{
		if (node->pos.x == from.x && node->pos.y == from.y)
			return (node->pos.z);
		node = node->next;
	}
	return (0);
}
