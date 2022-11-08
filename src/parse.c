/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:02 by pgros             #+#    #+#             */
/*   Updated: 2022/11/08 17:05:39 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	__check_highest(t_map **map, t_pointf3 *point3D)
{
	if ((*map)->highest == NULL)
		(*map)->highest = point3D;
	else
	{
		if (point3D->z > (*map)->highest->z)
			(*map)->highest = point3D;
	}
	return ;
}

void	__check_lowest(t_map **map, t_pointf3 *point3D)
{
	if ((*map)->lowest == NULL)
		(*map)->lowest = point3D;
	else
	{
		if (point3D->z < (*map)->lowest->z)
			(*map)->lowest = point3D;
	}
	return ;
}

int	__add_point_to_map(t_map **map, float x, float y, float z)
{
	t_pointf3	*point3D;
	t_lstmap	*new;

	point3D = malloc(sizeof(t_pointf3));
	if (point3D == NULL)
		return (-1);
	point3D->x = x;
	point3D->y = y;
	point3D->z = z;
	new = __lstmap_new(point3D);
	if (new == NULL)
		return (free(point3D), -1);
	if ((*map)->lstmap == NULL)
		__lstmap_add_back(&((*map)->lstmap), new);
	else
		__lstmap_add_back(&((*map)->last), new);
	(*map)->last = new;
	__check_lowest(map, point3D);
	__check_highest(map, point3D);
	return (0);
}

int	__count_columns(t_map **map, char *line)
{
	int	c;
	int	l;
	int	i;
	
	c = 0;
	i = 0;
	l = (*map)->nb_lines;
	(*map)->last = (*map)->lstmap;
	while (line[i] != '\0')
	{
		if (__is_nb_start(line, i) == 1)
		{
			if (__add_point_to_map(map, l, c, ft_atoi(line + i)) < 0)
				return (-1);
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
	int			len;
	int			col;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		col = __count_columns(map, line);
		(*map)->nb_lines++;
		if ((*map)->nb_columns == 0)
			(*map)->nb_columns = col;
		else
		{
			if (col != (*map)->nb_columns)
				(*map)->nb_columns = -1;
		}
		free(line);
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
		return (perror(""), NULL);
	__fill_map(&map, fd);
	close(fd);
	return (map);
}
