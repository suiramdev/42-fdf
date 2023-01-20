/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:31:37 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/20 13:39:58 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_gradient
{
	int	from;
	int	to;
}	t_gradient;

int	rgb_color(int r, int g, int b);
int	hexa_color(char *hexa);
int	lerp_color(int color1, int color2, int time);

#endif
