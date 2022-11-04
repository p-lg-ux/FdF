/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:38:14 by pgros             #+#    #+#             */
/*   Updated: 2022/11/04 17:23:03 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__print_map(t_map *map)
{
	ft_printf("-------------------------\nMAP:\n");
	if (map == NULL)
	{
		ft_printf("null\n-------------------------\n");
		return ;
	}
	ft_printf("nb_lines = %i\n", map->nb_lines);
	ft_printf("nb_columns = %i\n", map->nb_columns);
	ft_printf("-------------------------\n");
	return ;
}

// void	__free_maptab(t_maptab maptab)
// {
// 	int	i;
	
// 	if (maptab == NULL)
// 		return;
// 	i = 0;
// 	while (maptab[i] != NULL)
// 	{
// 		free(maptab[i]);
// 		i++;
// 	}
// 	free(maptab);
// }

void	__free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->highest != NULL)
		free(map->highest);
	if (map->lowest != NULL)
		free(map->lowest);
	if (map->maptab != NULL)
		free(map->maptab);
	free(map);
}
