/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:31:37 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/19 01:08:22 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int	rgb_color(int r, int g, int b);
int	hexa_color(char *hexa);
int	lerp_color(int color1, int color2, int time);

#endif
