/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:15:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 17:39:20 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "types/image.h"
#include "types/node.h"
#include "vector.h"

# define READ_SIZE 4096

typedef struct s_map
{
	t_node	*nodes;
	int		width;
	int		height;
	t_image	image;
}	t_map;

t_map	*load_map(char *path);
int		node_height(t_map *map, t_vector2 node);

#endif
