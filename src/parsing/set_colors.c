/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:44:51 by pgros             #+#    #+#             */
/*   Updated: 2022/11/28 19:54:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__set_rgb(int *rgb, float portion)
{
	if (portion < 0.25)
	{
		rgb[0] = 0;
		rgb[1] = 0 + (portion / 0.25) * 255;
		rgb[2] = 255;
	}
	else if (portion >= 0.25 && portion < 0.5)
	{
		rgb[0] = 0;
		rgb[1] = 255;
		rgb[2] = 255 - ((portion - 0.25) / 0.25) * 255;
	}
	else if (portion >= 0.5 && portion < 0.75)
	{
		rgb[0] = 0 + ((portion - 0.5) / 0.25) * 255;
		rgb[1] = 255;
		rgb[2] = 0;
	}
	else
	{
		rgb[0] = 255;
		rgb[1] = 255 - ((portion - 0.75) / 0.25) * 255;
		rgb[2] = 0;
	}
}

t_color	*__compute_color(t_lstmap *node, t_map *map)
{
	int		rgb[3];
	float	portion;

	portion = (node->point3D->z - map->lowest->z) / ((float)(map->range));
	__set_rgb((int *) rgb, portion);
	return (to_t_color((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]));
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
		__set_links(node, map);
		node = node->next;
	}
	return (0);
}
