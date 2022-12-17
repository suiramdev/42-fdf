/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:28:08 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 15:49:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "loaders.h"
#include "utils.h"

t_map	*load_map(char *path)
{
	t_map	*map;
	char	*line;
	int		fd;

	map = malloc(sizeof(t_map));
	map->data = NULL;
	map->width = 0;
	map->height = 0;
	fd = open(path, O_RDONLY);
	while ((line = read_line(fd)) != NULL)
	{
		map->width = ft_strlen(line);
		ft_strreplace(&map->data, ft_strnjoin(map->data, line, map->width));
		map->height++;
	}
	close(fd);
	return (map);
}
