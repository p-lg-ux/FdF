/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 15:51:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
// #include "fdf.h"
#include <stdio.h>

void	__apply_transform_to_map(t_data *data, t_matrix *transform)
{
	t_lstmap	*node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_product(*transform, node->point3d);
		node = node->next;
	}
}

void	__apply_transform(t_data *data, t_matrix *transform)
{
	t_lstmap	*node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_res_product(*transform, *(node->point3d),
			&(node->transformed));
		node = node->next;
	}
}

void	__put_map_to_im(t_data *data)
{
	t_lstmap	*node;

	__reset_background(data);
	__set_map_transform(data->map);
	__apply_transform(data, &(data->map->transform));
	node = data->map->lstmap;
	while (node != NULL)
	{
		if (node->right != NULL)
			__trace_segment(data, node, node->right);
		if (node->down != NULL)
			__trace_segment(data, node, node->down);
		node = node->next;
	}
}
