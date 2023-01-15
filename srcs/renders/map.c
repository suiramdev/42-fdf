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

# define TILE_WIDTH 50
# define TILE_HEIGHT 25
# define HEIGHT_SCALE 2

static t_vector2	node_pos(t_vector2 node, t_vector2 offset)
{
	return (t_vector2) { offset.x + (node.x - node.y) * TILE_WIDTH / 2, offset.y + (node.x + node.y) * TILE_HEIGHT / 2 };
}

/*
 * We draw the edge between the current and the next node on Y and X axis
 */
static void	draw_edges(t_map *map, t_vector2 from)
{
	t_vector2	offset;
	t_vector2	next_r;
	t_vector2	next_b;

	offset = (t_vector2) { WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3 };
	next_r = (t_vector2) { from.x + 1, from.y };
	next_b = (t_vector2) { from.x, from.y + 1 };
	if (next_r.x < map->width)
		draw_line(
			map->image,
			node_pos(from, (t_vector2) { offset.x, offset.y - node_height(map, from) * HEIGHT_SCALE}),
			node_pos(next_r, (t_vector2) { offset.x, offset.y - node_height(map, next_r) * HEIGHT_SCALE}),
			rgb(0, 255, 0)
		);
	if (next_b.y < map->height)
		draw_line(
			map->image,
			node_pos(from, (t_vector2) { offset.x, offset.y - node_height(map, from) * HEIGHT_SCALE}),
			node_pos(next_b, (t_vector2) { offset.x, offset.y - node_height(map, next_b) * HEIGHT_SCALE}),
			rgb(0, 255, 0)
		);
}

/*
 * This function renders a map struct on the window.
 * It creates an image, draws the lines on it, and displays the image on the window.
 */
int	render_map(t_map *map)
{
	t_vector2	node;

	map->image.ptr = mlx_new_image(g_fdf.mlx, WINDOW_WIDTH, WINDOW_WIDTH);
	map->image.data = mlx_get_data_addr(map->image.ptr, &map->image.bits_per_pixel, &map->image.size_line, &map->image.endian);
	node.y = 0;
	while (node.y < map->height)
	{
		node.x = 0;
		while (node.x < map->width)
		{
			draw_edges(map, node);
			node.x++;
		}
		node.y++;
	}
	mlx_put_image_to_window(g_fdf.mlx, g_fdf.win, map->image.ptr, 0, 0);
	return (0);
}
