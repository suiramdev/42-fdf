/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:04:49 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/17 20:52:39 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include "types/vector.h"

typedef struct s_node
{
	t_vector3		pos;
	struct s_node	*under;
	struct s_node	*next;
} t_node;

t_node	*new_node(t_node *nodes, t_vector3 pos);
t_node	*last_node(t_node *node);
void	insert_node(t_node **to, t_node *node);
void	empty_node(t_node *node);

#endif
