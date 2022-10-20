/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:02 by pgros             #+#    #+#             */
/*   Updated: 2022/10/20 17:47:42 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__count_lines_columns(t_map **map, int fd)
{
	char		*line;
	t_strtab	tab;
	int			nb_lines;
	int			nb_columns;
	
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nb_lines++;
		tab = ft_split(line, ' ');
		if (nb_columns == 0)
			nb_columns = __strtab_len(tab);
		else
		{
			if (nb_columns != __strtab_len(tab))
			{
				nb_columns = -1;
				free(line);
				__free_strtab(tab);
				break;
			}
		}
		free(line);
		__free_strtab(tab);
	}
	if (nb_lines > 0 && nb_columns > 0)
	{
		(*map)->nb_lines = nb_lines;
		(*map)->nb_columns = nb_columns;
	}
	else 
	{
		free(*map);
		*map = NULL;
	}
}

void	__fill_map(t_map **map, int fd)
{
	__count_lines_columns(map, fd);
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
		return (NULL);
	__fill_map(&map, fd);
	__print_map(map);
	close(fd);
	return (map);
}