/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:26:54 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/19 01:41:18 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	rgb_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	hexa_color(char *hexa)
{
	int output;
    int digit;

	digit = 0;
    while (*hexa) {
        digit = *hexa;
        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'a' && digit <= 'f') {
            digit = digit - 'a' + 10;
        } else if (digit >= 'A' && digit <= 'F') {
            digit = digit - 'A' + 10;
        } else {
            break;
        }
        output = output * 16 + digit;
        hexa++;
    }
    return output;
}

int	lerp_color(int color1, int color2, int time)
{
	int	r;
	int	g;
	int	b;

	r = ft_lerp((color1 >> 16) & 0xff, (color2 >> 16 & 0xff), time);
	g = ft_lerp((color1 >> 8) & 0xff, (color2 >> 8 & 0xff), time);
	b = ft_lerp(color1 & 0xff, color2 & 0xff, time);
	return (rgb_color(r, g, b));
}
