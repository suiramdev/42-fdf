/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:34:29 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/13 23:29:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERS_H
# define RENDERS_H

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

int		rgb(int r, int g, int b);
t_image	render_map(char *data);

#endif
