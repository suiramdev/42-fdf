/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:06:52 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/26 22:07:11 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/map.h"
#include "types/node.h"
#include "types/vector.h"
#include <stdlib.h>

/**
 * This is basically the chained list approach.
 */

t_node	*new_node(t_node *nodes, t_vector3 pos, int color)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->pos = pos;
		node->color = color;
		node->under = nodes;
		while (node->under != NULL)
		{
			if (node->under->pos.x == pos.x && node->under->pos.y == pos.y - 1)
				break ;
			node->under = node->under->next;
		}
		node->next = NULL;
	}
	return (node);
}

t_node	*last_node(t_node *node)
{
	if (node != NULL)
		while (node->next != NULL)
			node = node->next;
	return (node);
}

void	insert_node(t_node **to, t_node *node)
{
	t_node	*last;

	last = last_node(*to);
	if (last != NULL)
		last->next = node;
	else
		*to = node;
}

void	empty_node(t_node *node)
{
	t_node	*next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
