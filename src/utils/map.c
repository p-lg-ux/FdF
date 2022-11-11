/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:38:14 by pgros             #+#    #+#             */
/*   Updated: 2022/11/11 18:26:28 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>
#include <stdio.h>

void	__print_lstmap(t_lstmap *maptab)
{
	int	i;

	i = 0;
	printf("lstmap =\n");
	while (maptab != NULL && i < 700)
	{
		i++;
		__print_pointf3(maptab->point3D);
		printf("\n");
		maptab = maptab->next;
	}
}

void	__print_map(t_map *map)
{
	printf("-------------------------\nMAP:\n");
	if (map == NULL)
	{
		printf("null\n-------------------------\n");
		return ;
	}
	printf("nb_lines = %i\n", map->nb_lines);
	printf("nb_columns = %i\n", map->nb_columns);
	if (map->highest != NULL)
	{
		printf("highest = ");
		__print_pointf3(map->highest);
		printf("\n");
	}
	if (map->lowest != NULL)
	{
		printf("lowest = ");
		__print_pointf3(map->lowest);
		printf("\n");
	}
	if (map->lstmap != NULL)
		__print_lstmap(map->lstmap);
	printf("-------------------------\n");
	return ;
}

void	__free_map(t_map *map)
{
	if (map == NULL)
		return ;
	// if (map->highest != NULL)
	// 	free(map->highest);
	// if (map->lowest != NULL)
	// 	free(map->lowest);
	if (map->lstmap != NULL)
		__lstmap_clear(&(map->lstmap));
	free(map);
}
