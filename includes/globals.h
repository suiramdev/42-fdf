/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:54:18 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/02 15:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 800
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 600
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

extern t_mlx	g_mlx;

#endif
