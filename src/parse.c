/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:02 by pgros             #+#    #+#             */
/*   Updated: 2022/11/04 17:07:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	__fill_maptab(t_map	**map, int fd)
// {
	
// }
int	__nblen(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ')
		i++;
	return (i);
}

int	__is_nb_start(char *line, int i)
{
	if (i == 0)
	{
		if (line[i] == '-' || ft_isdigit(line[i]) == 1)
			return (1);
	}
	else
	{
		if (line[i - 1] == ' '
			&& (line[i] == '-' || ft_isdigit(line[i]) == 1))
			return (1);
	}
	return (0);
}

int	__count_columns(char *line)
{
	int	c;
	int	i;
	
	c = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (__is_nb_start(line, i) == 1)
		{
			c++;
			i += __nblen(line + i);
		}
		else
			i++;
	}
	return (c);
}

void	__count_lines_columns(t_map **map, int fd)
{
	char		*line;
	// t_strtab	tab;
	int			len;
	int			col;

	// line = get_next_line(fd);
	// if (line == NULL)
	// 	return ;
	// __fill_maptab(map, line);
	// (*map)->nb_lines++;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(*map)->nb_lines++;
		col = __count_columns(line);
		if ((*map)->nb_columns == 0)
			(*map)->nb_columns = col;
		else
		{
			if (col != (*map)->nb_columns)
				(*map)->nb_columns = -1;
		}
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
	if ((*map)->nb_lines <= 0)
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
		return (perror(""), NULL);
	__fill_map(&map, fd);
	close(fd);
	return (map);
}
