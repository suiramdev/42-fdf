/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2023/01/02 15:39:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include "globals.h"
#include "loaders.h"

static t_cell	*last_cell(t_cell *cell)
{
	if (cell != NULL)
		while (cell->next != NULL)
			cell = cell->next;
	return (cell);
}

static void	insert_cell(t_cell **cell, int height)
{
	t_cell	*new;
	t_cell	*last;

	new = malloc(sizeof(t_cell));
	if (new)
	{
		new->height = height;
		new->next = NULL;
		last = last_cell(*cell);
		if (last != NULL)
			last->next = new;
		else
			*cell = new;
	}
}

static int	insert_cells(t_map *map, char *line)
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
			insert_cell(&map->data, ft_atoi(ft_substr(line, i, j - i)));
			i = j;
		}
	}
	return (count);
}

t_cell	*get_cell(t_map *map, t_vector pos)
{
	int		cellX;
	int		cellY;
	t_cell	*cell;

	if (pos.x >= map->width || pos.y >= map->height)
		return (NULL);
	cellX = 0;
	cellY = 0;
	cell = map->data;
	while (cell != NULL)
	{
		if (cellX == pos.x && cellY == pos.y)
			break ;
		cell = cell->next;
		cellX++;
		if (cellX >= map->width)
		{
			cellX = 0;
			cellY++;
		}
	}
	return (cell);
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
		{
			map->width = insert_cells(map, line);
			map->height++;
			free(line);
		}
		close(fd);
	}
	return (map);
}
