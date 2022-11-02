/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:02 by pgros             #+#    #+#             */
/*   Updated: 2022/11/02 15:25:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__fill_maptab(t_map	**map, int fd)
{
	
}

void	__count_lines_columns(t_map **map, int fd)
{
	char		*line;
	// t_strtab	tab;
	int			len;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(*map)->nb_lines++;
		// tab = ft_split(line, ' ');
		// len = __strtab_len(tab);
		// if ((*map)->nb_columns == 0)
		// 	(*map)->nb_columns = len;
		// else
		// {
		// 	if ((*map)->nb_columns != len)
		// 		(*map)->nb_columns = -1;
		// }
		free(line);
		// __free_strtab(tab);
	}
}

void	__fill_map(t_map **map, int fd)
{
	__count_lines_columns(map, fd);
	if ((*map)->nb_lines <= 0 || (*map)->nb_columns <= 0)
	{
		__free_map(*map);
		*map = NULL;
	}
}

t_map	*parse(char *filepath)
{
	t_map	*map;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror(filepath);
		exit(EXIT_FAILURE);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (perror, NULL);
	__fill_map(&map, fd);
	close(fd);
	return (map);
}
