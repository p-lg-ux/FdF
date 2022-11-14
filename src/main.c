/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:48 by pgros             #+#    #+#             */
/*   Updated: 2022/11/14 16:27:53 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	
	(void)argv;
	if (argc != 2)
	{
		printf("Error\n");//TODO : change to ft_printf
		exit(EXIT_FAILURE);
	}
	map = __parse(argv[1]);
	__print_map(map);
	if (map == NULL)
		return (1);
	__set_colors(map);
	__free_map(map);
	return (0);
}
