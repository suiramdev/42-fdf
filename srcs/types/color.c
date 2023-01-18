/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:26:54 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/18 02:37:56 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
