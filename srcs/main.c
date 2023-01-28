/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:19:44 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/28 18:17:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/fdf.h"
#include "types/map.h"
#include "hooks.h"
#include "types/node.h"
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

static t_fdf	*init(char *path)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = load_map(path);
	if (!fdf->map)
		return (NULL);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		empty_node(fdf->map->nodes);
		free(fdf->map);
		return (NULL);
	}
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!fdf->win)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		empty_node(fdf->map->nodes);
		free(fdf->map);
		return (NULL);
	}
	return (fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc < 2)
		return (EXIT_FAILURE);
	fdf = init(argv[1]);
	if (!fdf)
		return (EXIT_FAILURE);
	mlx_loop_hook(fdf->mlx, render_map, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_hook(fdf->win, 33, 1L << 17, close_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->map->image.ptr);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	empty_node(fdf->map->nodes);
	free(fdf->map);
	free(fdf);
	return (EXIT_SUCCESS);
}
