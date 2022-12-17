/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:54:18 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/16 18:46:23 by marvin           ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

extern t_mlx	g_mlx;

#endif
