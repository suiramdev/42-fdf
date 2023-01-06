/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:15:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 20:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "vector.h"

typedef struct s_tile
{
	t_vector3		pos;
	struct s_tile	*next;
}	t_tile;

typedef struct s_map
{
	t_tile	*data;
	int		width;
	int		height;
}	t_map;

t_map	*load_map(char *path);

#endif
