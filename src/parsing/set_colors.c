/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:44:51 by pgros             #+#    #+#             */
/*   Updated: 2022/11/19 16:18:08 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	*__compute_color(t_lstmap *node, t_map *map)
{
	int		R;
	int		G;
	int		B;
	float	portion;

	portion = (node->point3D->z - map->lowest->z) / ((float) (map->range));
	// printf("portion = %f\t", portion);
	R = MIN_R + portion * D_R ;
	G = MIN_G + portion * D_G ;
	B = MIN_B + portion * D_B ;
	// printf("R, G, B = %i, %i, %i\n", R, G, B);
	return (to_t_color((R << 16) + (G << 8) + B));
}

t_color	*__define_color(t_lstmap *node, t_map *map)
{
	t_color	*color;

	if (node->point3D->z == map->lowest->z)
		color = to_t_color(COLOR_MIN);
	else if (node->point3D->z == map->highest->z)
		color = to_t_color(COLOR_MAX);
	else
		color = __compute_color(node, map);
	return (color);
}

void	__set_links(t_lstmap *node, t_map *map)
{
	int			i;
	t_lstmap	*tmp;
	
	if (node->point3D->y == map->nb_columns - 1)
		node->right = NULL;
	else
		node->right = node->next;
	if (node->point3D->x == map->nb_lines - 1)
		node->down = NULL;
	else
	{
		i = 0;
		tmp = node;
		while (i < map->nb_columns && tmp != NULL)
		{
			tmp = tmp->next;
			i++;
		}
		node->down = tmp;
	}
}

int	__set_colors(t_map *map)
{
	t_lstmap	*node;

	node = map->lstmap;
	while (node != NULL)
	{
		node->color = __define_color(node, map);
		if (node->color == NULL)
			return (1);
		// printf("R, G, B = %i, %i, %i\tcolor = %X\n", node->color->R, node->color->G, node->color->B, node->color->val);
		__set_links(node, map);
		node = node->next;
	}
	return (0);
}
