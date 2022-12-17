/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:25:52 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/13 23:27:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renders.h"

void	draw_pixel(t_image image, t_vector pos, int color)
{
	char	*pixel;

	pixel = image.ptr + (pos.y * image.size_line + pos.x * image.bits_per_pixel);
	*(int *)pixel = color;
}
