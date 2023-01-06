/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:25:52 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/06 20:25:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/image.h"
#include "types/vector.h"

void	draw_pixel(t_image image, t_vector2 pos, int color)
{
	char    *pixel;

    pixel = image.data + (pos.y * image.size_line + pos.x * (image.bits_per_pixel / 8));
	*(int *)pixel = color;
}
