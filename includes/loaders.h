/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:18:15 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 15:49:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADERS_H
# define LOADERS_H

#include "renders.h"

typedef struct s_map
{
	char	*data;
	int		width;
	int		height;
}	t_map;

t_map	*load_map(char *path);

#endif
