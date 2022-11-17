/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/17 14:44:54 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdio.h>

void	__put_map_to_im(t_data *data)
{
	t_lstmap *node;

	node = data->map->lstmap;
	printf("data->img = %p\n", &(data->img));
	while (node != NULL)
	{
		// printf("x = %i\t y = %i\tcolor = %X\n", node->point3D->x, node->point3D->y, node->color->val);
		__img_pix_put(&(data->img), node->point3D->y, node->point3D->x, node->color->val);
		node = node->next;
	}
}