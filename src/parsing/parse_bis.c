/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:43:07 by pgros             #+#    #+#             */
/*   Updated: 2022/11/09 13:44:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__nblen(char *line)
{
	int	i;

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
