/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:19:44 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/15 18:15:50 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "types/fdf.h"
#include "types/map.h"
#include "renders.h"
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

t_fdf	g_fdf;

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc < 2)
		return (EXIT_FAILURE);
	g_fdf.mlx = mlx_init();
	g_fdf.win = mlx_new_window(g_fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	map = load_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	mlx_loop_hook(g_fdf.mlx, render_map, map);
	mlx_loop(g_fdf.mlx);
	return (EXIT_SUCCESS);
}
