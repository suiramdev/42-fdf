/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:15:40 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 09:47:14 by mnouchet         ###   ########.fr       */
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
}	t_map;

t_map	*load_map(char *path);

#endif
