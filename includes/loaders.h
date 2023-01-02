/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:18:15 by marvin            #+#    #+#             */
/*   Updated: 2023/01/02 15:39:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADERS_H
# define LOADERS_H

#include "globals.h"

typedef struct s_cell
{
	int				height;
	struct s_cell	*next;
}	t_cell;

typedef struct s_map
{
	t_cell	*data;
	int		width;
	int		height;
}	t_map;

t_map	*load_map(char *path);
t_cell	*get_cell(t_map *map, t_vector pos);

#endif
