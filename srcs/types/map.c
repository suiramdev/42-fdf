/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 02:21:35 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/map.h"
#include "types/node.h"
#include "types/vector.h"
#include "types/color.h"
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Reads and parses the content of a map file, line by line, and fills
 * the fields of a t_map struct with the data read from the file.
 *
 * @param map A pointer to a t_map struct that will be filled with the
 * data read from the file.
 * @parm line A string containing a line of text from the map file.
 */
static void	fill_map(t_map *map, char line[READ_SIZE + 1])
{
	t_vector3	pos;
	int			color;

	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\n'))
		{
			if (*line == '\n' && *(line + 1))
			{
				map->width = 0;
				map->height++;
			}
			line++;
		}
		if (*line)
			break ;
		pos = (t_vector3){map->width, map->height, ft_atoi(line)};
		while (*line == '-' || ft_isdigit(*line))
			line++;
		color = rgb_color(255, 255, 255);
		if (*line == ',' && *(line + 1) == '0' && *(line + 2) == 'x')
			color = hexa_color(line + 3);
		insert_node(&map->nodes, new_node(map->nodes, pos, color));
		map->width++;
		while (*line && *line != ' ' && *line != '\n')
			line++;
	}
}

/**
 * Reads and parses a map file, and returns a pointer to a t_map struct
 * containing the data read from the file.
 *
 * @param path The file path of the map file to be loaded.
 * @return A pointer to the filled t_map struct.
 */
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
		bytes = 1;
		while (bytes > 0)
		{
			bytes = read(fd, line, READ_SIZE);
			line[bytes] = '\0';
			fill_map(map, line);
		}
		close(fd);
	}
	return (map);
}
