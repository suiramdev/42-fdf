/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:34:29 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/02 15:37:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERS_H
# define RENDERS_H

#include "loaders.h"
#include "globals.h"

typedef struct s_image
{
	void	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

int		rgb(int r, int g, int b);
void	draw_pixel(t_image image, t_vector pos, int color);
t_image	render_map(t_map *map);

#endif
