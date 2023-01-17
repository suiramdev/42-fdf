/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:06:52 by mnouchet          #+#    #+#             */
/*   Updated: 2023/01/17 20:52:26 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/map.h"
#include "types/node.h"
#include "stdlib.h"
#include "types/vector.h"

t_node	*new_node(t_node *nodes, t_vector3 pos)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->pos = pos;
		node->under = nodes;
		while (node->under != NULL)
		{
			if (node->under->pos.x == pos.x && node->under->pos.y == pos.y - 1)
				break;
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

	if ((last = last_node(*to)) != NULL)
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