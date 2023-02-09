/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:24:00 by mnouchet          #+#    #+#             */
/*   Updated: 2023/02/09 14:54:40 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/fdf.h"
#include <stdlib.h>
#include <mlx.h>

static void	free_fdf(t_fdf *fdf)
{
	if (fdf->map)
	{
		empty_node(fdf->map->nodes);
		free(fdf->map);
	}
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
}

t_fdf	*init_fdf(char *path)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = load_map(path);
	if (!fdf->map)
	{
		free_fdf(fdf);
		return (NULL);
	}
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_fdf(fdf);
		return (NULL);
	}
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!fdf->win)
	{
		free_fdf(fdf);
		return (NULL);
	}
	return (fdf);
}
