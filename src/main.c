/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:48 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 18:32:23 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	data;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	map = __parse(argv[1]);
	if (map == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (__set_colors(map) != 0)
	{
		ft_printf("Error\n");
		__free_map(map);
		exit(EXIT_FAILURE);
	}
	data.map = map;
	__mlx_display(&data);
	__free_map(map);
	return (0);
}
