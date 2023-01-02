/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:18:15 by marvin            #+#    #+#             */
/*   Updated: 2022/12/31 21:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADERS_H
# define LOADERS_H

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
t_cell	*get_cell(t_map *map, int x, int y);

#endif
