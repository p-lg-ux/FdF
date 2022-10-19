/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:11 by pgros             #+#    #+#             */
/*   Updated: 2022/10/19 19:07:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point2D
{
	int	x;
	int	y;
}	t_point2D;

typedef struct s_point3D
{
	float	x;
	float	y;
	float	z;
}	t_point3D;

typedef struct s_map
{
	int			nb_lines;
	int			nb_columns;
	int			lowest;
	int			highest;
	t_point3D	**map_tab;
}	t_map;
