/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:19:44 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/23 19:52:58 by mnouchet         ###   ########.fr       */
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
	if (fdf)
	{
		fdf->map = load_map(path);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
		if (!fdf->map || !fdf->mlx || !fdf->win)
			return (NULL);
	}
	return (fdf);
}

int	main(int argc, char **argv, char **env)
{
	t_fdf	*fdf;

	if (!env || *env)
		return (EXIT_FAILURE);
	if (argc < 2)
		return (EXIT_FAILURE);
	fdf = init(argv[1]);
	if (!fdf)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(fdf->mlx, render_map, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_hook(fdf->win, 33, 1L << 17, close_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	empty_node(fdf->map->nodes);
	free(fdf->mlx);
	free(fdf->win);
	free(fdf->map);
	free(fdf);
	return (EXIT_SUCCESS);
}
