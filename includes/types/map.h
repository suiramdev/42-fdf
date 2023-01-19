/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:15:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 03:28:24 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "types/image.h"
# include "types/node.h"
# include "vector.h"

# define READ_SIZE 4096

typedef struct s_map
{
	t_node	*nodes;
	int		width;
	int		height;
	t_image	image;
}	t_map;

t_map	*load_map(char *path);

#endif
