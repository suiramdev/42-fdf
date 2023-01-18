/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:34:29 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/18 02:32:24 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERS_H
# define RENDERS_H

#include "types/image.h"
#include "types/vector.h"
#include "types/map.h"

void	draw_pixel(t_image image, t_vector2 pos, int color);
void	draw_line(t_image image, t_vector2 start, t_vector2 end, int color);
int		render_map(t_map *map);

#endif
