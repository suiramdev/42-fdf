/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:48:19 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/22 21:10:35 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "types/fdf.h"
#include <stdio.h>

/**
 * Handle map's mouse events 
 *
 * @param key_code An integer corresponding to the key actionned.
 * @param fdf
 */
int	mouse_hook(int key_code, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key_code == 4)
	{
		fdf->map->tile_width -= 1;
		fdf->map->tile_height = fdf->map->tile_width / 2;
	}
	if (key_code == 5)
	{
		fdf->map->tile_width += 1;
		fdf->map->tile_height = fdf->map->tile_width / 2;
	}
	return (0);
}

/**
 * Handle map's key events 
 *
 * @param key_code An integer corresponding to the key actionned.
 * @param fdf
 */
int	key_hook(int key_code, t_fdf *fdf)
{
	if (key_code == 65307)
		mlx_loop_end(fdf->mlx);
	return (0);
}
