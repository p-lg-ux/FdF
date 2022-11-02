/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:48 by pgros             #+#    #+#             */
/*   Updated: 2022/11/02 18:07:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	// t_map	*map;
	t_int2		vec_i2;
	t_int3		vec_i3;
	t_int2		a;
	t_int2		b;
	t_float3	vec_f3;
	
	if (argc != 2)
	{
		ft_printf("Error\n");//TODO : change to ft_printf
		// exit(EXIT_FAILURE);
	}
	vec_i2 = (t_int2){1, 2};
	vec_i3 = (t_int3){1, 2, 3};
	printf("i2 : [%i, %i]\n", vec_i2.x, vec_i2.y);
	printf("i3 : [%i, %i, %i]\n", vec_i3.x, vec_i3.y, vec_i3.z);
	a = vec_i2;
	vec_i2 += 1;
	b = vec_i2;
	printf("i2 : [%i, %i]\n", vec_i2.x, vec_i2.y);
	printf("a : [%i, %i]\n", a.x, a.y);
	printf("b : [%i, %i]\n", b.x, b.y);
	a = a * b;
	printf("a : [%i, %i]\n", a.x, a.y);
	
	// map = parse(argv[1]);
	// __print_map(map);
	// __free_map(map);
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
