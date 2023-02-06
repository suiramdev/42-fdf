/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:48:15 by mnouchet          #+#    #+#             */
/*   Updated: 2023/02/06 09:47:26 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/vector.h"
#include "types/map.h"
#include "draws.h"
#include <stdlib.h>

static t_vector2	convert_pos(t_map *map, t_node *node)
{
	t_vector2	offset;

	offset = (t_vector2){
		map->image.width / 2,
		map->image.height / 2 - (map->height * map->tile_height) / 2
	};
	offset.y -= node->pos.z * 2;
	return ((t_vector2){
		offset.x + (node->pos.x - node->pos.y) * map->tile_width / 2,
		offset.y + (node->pos.x + node->pos.y) * map->tile_height / 2
	});
}

/**
 * This function will draw the right and bottom connecting edge
 * of the given node.
 *
 * @param map
 * @param node
 */
void	draw_node(t_map *map, t_node *node)
{
	if (node->next != NULL && node->next->pos.y == node->pos.y)
		draw_line(
			map->image,
			convert_pos(map, node),
			convert_pos(map, node->next),
			(t_gradient){node->color, node->next->color});
	if (node->under != NULL)
		draw_line(
			map->image,
			convert_pos(map, node),
			convert_pos(map, node->under),
			(t_gradient){node->color, node->under->color});
}
