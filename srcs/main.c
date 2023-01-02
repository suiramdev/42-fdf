/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:54:54 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/24 00:06:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "loaders.h"

t_mlx	g_mlx;

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		return (EXIT_FAILURE);
	//g_mlx.ptr = mlx_init();
	//g_mlx.win = mlx_new_window(g_mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	map = load_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
