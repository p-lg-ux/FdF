/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:48:33 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 15:52:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"
#include "map.h"
#include <stdlib.h>

t_lstmap	*__lstmap_new(t_point_i3 *point3D)
{
	t_lstmap	*new_node;

	new_node = (t_lstmap *) ft_calloc(1, sizeof(t_lstmap));
	if (!new_node)
		return (new_node);
	new_node->point3d = point3D;
	new_node->next = NULL;
	return (new_node);
}

int	__lstmap_size(t_lstmap *lst)
{
	int	nb_nodes;

	nb_nodes = 0;
	while (lst)
	{
		nb_nodes++;
		lst = lst->next;
	}
	return (nb_nodes);
}

void	__lstmap_add_back(t_lstmap **lst, t_lstmap *new)
{
	t_lstmap	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	while (last && last->next)
		last = last->next;
	if (last == NULL)
	{
		*lst = new;
		return ;
	}
	last->next = new;
	return ;
}

void	__lstmap_clear(t_lstmap **lst)
{
	t_lstmap	*next;

	if (!lst || !(*lst))
		return ;
	next = (*lst)->next;
	while (next)
	{
		if ((*lst)->point3d != NULL)
			free((*lst)->point3d);
		if ((*lst)->color != NULL)
			free((*lst)->color);
		free((*lst));
		*lst = next;
		next = next->next;
	}
	if ((*lst)->point3d != NULL)
		free((*lst)->point3d);
	if ((*lst)->color != NULL)
		free((*lst)->color);
	free((*lst));
	*lst = NULL;
}
