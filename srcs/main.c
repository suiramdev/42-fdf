/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:54:54 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/17 15:53:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "globals.h"
#include "loaders.h"

t_mlx	g_mlx;

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	if (argc < 2)
		return (EXIT_FAILURE);
	g_mlx.ptr = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	mlx_loop(g_mlx.ptr);
	map = load_map(argv[1]);
	i = 0;
	while (map->data[i])
	{
		write(1, &map->data[i], 1);
		i++;
	}
	return (EXIT_SUCCESS);
}
