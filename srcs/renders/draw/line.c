/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:29:11 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 02:49:08 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/image.h"
#include "types/vector.h"
#include "types/color.h"
#include "renders.h"
#include <libft.h>

void	draw_line(t_image image, t_vector2 start, t_vector2 end, int start_color, int end_color)
{
	t_vector2	distance;
	t_vector2	step;
	t_vector2	current;
	int			error;
	int			time;

	distance = (t_vector2){end.x - start.x, end.y - start.y};
	step = (t_vector2){1, 1};
	if (distance.x < 0)
		step.x = -1;
	if (distance.y < 0)
		step.y = -1;
	current = (t_vector2){start.x, start.y};
	if (ft_abs(distance.x) > ft_abs(distance.y))
	{
		error = ft_abs(distance.x);
		while (ft_abs(current.x - start.x) < ft_abs(distance.x))
		{
			time = 0xff * ft_abs(current.x - start.x) / ft_abs(distance.x);
			draw_pixel(
				image,
				current,
				lerp_color(start_color, end_color, time));
			current.x += step.x;
			error -= ft_abs(distance.y);
			if (error < 0)
			{
				current.y += step.y;
				error += ft_abs(distance.x);
			}
		}
	}
	else
	{
		error = ft_abs(distance.y);
		while (ft_abs(current.y - start.y) < ft_abs(distance.y))
		{
			time = 0xff * ft_abs(current.y - start.y) / ft_abs(distance.y);
			draw_pixel(
				image,
				current,
				lerp_color(start_color, end_color, time));
			current.y += step.y;
			error -= ft_abs(distance.x);
			if (error < 0)
			{
				current.x += step.x;
				error += ft_abs(distance.y);
			}
		}
	}
}
