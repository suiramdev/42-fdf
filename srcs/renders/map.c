/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:01:49 by mnouchet          #+#    #+#             */
/*   Updatedh 2023/01/15 15:48:59 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/fdf.h"
#include "types/image.h"
#include "types/vector.h"
#include "types/map.h"
#include "globals.h"
#include "renders.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

# define TILE_WIDTH 20
# define TILE_HEIGHT 10
# define HEIGHT_SCALE 2

static t_vector2	convert_pos(t_vector2 pos, t_vector2 offset)
{
	return (t_vector2) { offset.x + (pos.x - pos.y) * TILE_WIDTH / 2, offset.y + (pos.x + pos.y) * TILE_HEIGHT / 2 };
}

/*
 * We draw the edge between the current and the next node on Y and X axis
 */
static void	draw_node(t_map *map, t_node *node)
{
	t_vector2	offset;

	offset = (t_vector2) { map->image.width / 2, map->image.height / 2 - (map->height * TILE_HEIGHT) / 2 };
	if (node->next != NULL && node->next->pos.y == node->pos.y)
		draw_line(
			map->image,
			convert_pos((t_vector2) { node->pos.x, node->pos.y }, (t_vector2) { offset.x, offset.y - node->pos.z * HEIGHT_SCALE}),
			convert_pos((t_vector2) { node->next->pos.x, node->next->pos.y }, (t_vector2) { offset.x, offset.y - node->next->pos.z * HEIGHT_SCALE}),
			rgb(0, 255, 0)
		);
	if (node->under != NULL)
		draw_line(
			map->image,
			convert_pos((t_vector2) { node->pos.x, node->pos.y }, (t_vector2) { offset.x, offset.y - node->pos.z * HEIGHT_SCALE}),
			convert_pos((t_vector2) { node->under->pos.x, node->under->pos.y }, (t_vector2) { offset.x, offset.y - node->under->pos.z * HEIGHT_SCALE}),
			rgb(0, 255, 0)
		);
}

/*
 * This function renders a map struct on the window.
 * It creates an image, draws the lines on it, and displays the image on the window.
 */
int	render_map(t_map *map)
{
	t_node	*node;

	if (map->image.ptr != NULL)
		mlx_destroy_image(g_fdf.mlx, map->image.ptr);
	map->image.width = WINDOW_WIDTH;
	map->image.height = WINDOW_HEIGHT;
	map->image.ptr = mlx_new_image(g_fdf.mlx, map->image.width, map->image.height);
	map->image.data = mlx_get_data_addr(map->image.ptr, &map->image.bits_per_pixel, &map->image.size_line, &map->image.endian);
	node = map->nodes;
	while (node != NULL)
	{
		draw_node(map, node);
		node = node->next;
	}
	mlx_put_image_to_window(g_fdf.mlx, g_fdf.win, map->image.ptr, 0, 0);
	return (0);
}
