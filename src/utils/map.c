/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:38:14 by pgros             #+#    #+#             */
/*   Updated: 2022/11/28 15:25:49 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "lib42.h"
#include <stdlib.h>
#include <stdio.h>

// void	__print_lstmap(t_lstmap *maptab)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("lstmap =\n");
// 	while (maptab != NULL && i < 700)
// 	{
// 		i++;
// 		__print_point_i3(maptab->point3D);
// 		ft_printf("\tR, G, B = %i, %i, %i",
// 			maptab->color->R, maptab->color->G, maptab->color->B);
// 		ft_printf("\tcolor = %X", maptab->color->val);
// 		ft_printf("\n");
// 		maptab = maptab->next;
// 	}
// }

// void	__print_map(t_map *map)
// {
// 	ft_printf("-------------------------\nMAP:\n");
// 	if (map == NULL)
// 	{
// 		ft_printf("null\n-------------------------\n");
// 		return ;
// 	}
// 	ft_printf("nb_lines = %i\n", map->nb_lines);
// 	ft_printf("nb_columns = %i\n", map->nb_columns);
// 	if (map->highest != NULL)
// 	{
// 		ft_printf("highest = ");
// 		__print_point_i3(map->highest);
// 		ft_printf("\n");
// 	}
// 	if (map->lowest != NULL)
// 	{
// 		ft_printf("lowest = ");
// 		__print_point_i3(map->lowest);
// 		ft_printf("\n");
// 	}
// 	if (map->lstmap != NULL)
// 		__print_lstmap(map->lstmap);
// 	ft_printf("-------------------------\n");
// 	return ;
// }

void	__free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->lstmap != NULL)
		__lstmap_clear(&(map->lstmap));
	free(map);
}
