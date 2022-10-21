/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:11 by pgros             #+#    #+#             */
/*   Updated: 2022/10/21 17:06:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

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

#endif