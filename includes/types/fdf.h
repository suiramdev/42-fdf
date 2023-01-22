/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:08:02 by marvin            #+#    #+#             */
/*   Updated: 2023/01/22 01:06:26 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "types/map.h"

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1000
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 750
# endif

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_fdf;

#endif
