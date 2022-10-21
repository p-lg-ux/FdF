/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:48 by pgros             #+#    #+#             */
/*   Updated: 2022/10/21 17:12:52 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\n");//TODO : change to ft_printf
		exit(EXIT_FAILURE);
	}
	map = parse(argv[1]);
	__print_map(map);
	__free_map(map);
	return (0);
	// int	fd;
	// char *filename;
	// int	i;
	// char	*line_str;

	// filename = argv[1];
	// fd = open(filename, O_RDONLY);
	// if (fd < 0)
	// {
	// 		printf("Open error");
	// 		return (0);
	// }
	// i=1;
	// while (i)
	// {
	// 	line_str = get_next_line(fd);
	// 	if (line_str == NULL)
	// 			break ;
	// 	printf("%s", line_str);
	// 	free(line_str);
	// 	i++;
	// }
	// close(fd);
	// return (0);
}
