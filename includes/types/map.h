/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:15:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 21:53:57 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "types/image.h"
# include "types/node.h"
# include "vector.h"

typedef struct s_map
{
	t_node	*nodes;
	int		width;
	int		height;
	t_image	image;
	int		tile_width;
	int		tile_height;
	int		height_scale;
}	t_map;

t_map	*load_map(char *path);

#endif
