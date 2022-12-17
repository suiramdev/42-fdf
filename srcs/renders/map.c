/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:01:49 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/07 17:24:58 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "globals.h"
#include "renders.h"

t_image	render_map(char *data)
{
	t_image	image;

	image.ptr = mlx_new_image(g_mlx.ptr, WINDOW_WIDTH, WINDOW_WIDTH);
	mlx_get_data_addr(image.ptr, &image.bits_per_pixel, &image.size_line, &image.endian);
	return (image);
}
