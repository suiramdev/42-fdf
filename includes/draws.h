/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:34:29 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:25 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWS_H
# define DRAWS_H

# include "types/image.h"
# include "types/vector.h"
# include "types/color.h"
# include "types/map.h"
# include "types/node.h"

void	draw_pixel(t_image image, t_vector2 pos, int color);
void	draw_line(t_image image, t_vector2 start, t_vector2 end,
			t_gradient gradient);
void	draw_node(t_map *map, t_node *node);

#endif
