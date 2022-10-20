/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:38:14 by pgros             #+#    #+#             */
/*   Updated: 2022/10/20 17:47:55 by pgros            ###   ########.fr       */
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
}