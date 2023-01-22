/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:05:28 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/22 01:54:42 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "types/map.h"
# include "types/fdf.h"

int	render_map(t_map *map);
int	mouse_hook(int key_code, t_fdf *fdf);
int	key_hook(int key_code, t_fdf *fdf);

#endif
