/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 21:53:25 by mnouchet         ###   ########.fr       */
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
 * Parses the colour of the given line into an integer.
 * To be honest, this splitting was more for the norminette.
 *
 * @param line A string containing a line of text from the map file.
 * @return The corresponding color integer value
 */
static int	extract_color(char *line)
{
	int	color;

	color = rgb_color(255, 255, 255);
	if (*line == ',' && *(line + 1) == '0' && *(line + 2) == 'x')
		color = hexa_color(line + 3);
	return (color);
}

/**
 * Reads and parses the content of a map file, line by line, and fills
 * the fields of a t_map struct with the data read from the file.
 *
 * @param map A pointer to a t_map struct that will be filled with the
 * data read from the file.
 * @parm line A string containing a line of text from the map file.
 */
static void	fill_map(t_map *map, char *line)
{
	t_vector3	pos;

	map->width = 0;
	while (*line)
	{
		while (*line && *line == ' ') 
			line++;
		if (!*line)
			break ;
		pos = (t_vector3){map->width, map->height, ft_atoi(line)};
		while (*line == '-' || ft_isdigit(*line))
			line++;
		insert_node(&map->nodes, new_node(map->nodes, pos, extract_color(line)));
		map->width++;
		while (*line && *line != ' ')
			line++;
	}
	map->height++;
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
	char		*line;
	int			fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->nodes = NULL;
	map->height = 0;
	map->width = 0;
	fd = open(path, O_RDONLY);
	line = ft_gnl(fd);
	while (line != NULL)
	{
		fill_map(map, line);
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	map->tile_width = 100;
	map->tile_height = 50;
	map->height_scale = 2;
	return (map);
}
