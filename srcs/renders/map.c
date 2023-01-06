/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:01:49 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/06 20:26:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/fdf.h"
#include "types/map.h"
#include "globals.h"
#include "renders.h"
#include <mlx.h>

int	render_map(t_map *map)
{
	t_image	image;
	t_tile	*tile;

	image.ptr = mlx_new_image(g_fdf.mlx, WINDOW_WIDTH, WINDOW_WIDTH);
	image.data = mlx_get_data_addr(image.ptr, &image.bits_per_pixel, &image.size_line, &image.endian);
	tile = map->data;
	while (tile && tile->next)
	{
		draw_tile(image, *tile);
		tile = tile->next;
	}
	mlx_put_image_to_window(g_fdf.mlx, g_fdf.win, image.ptr, 0, 0);
	return (0);
}
