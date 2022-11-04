/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:11 by pgros             #+#    #+#             */
/*   Updated: 2022/11/04 17:19:52 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H


// typedef int		t_int2 __attribute__((vector_size(2 * sizeof(int))));
// typedef int		t_int3 __attribute__((vector_size(3 * sizeof(int))));

typedef int		t_pointi2 __attribute__((ext_vector_type(2)));
typedef int		t_pointi3 __attribute__((ext_vector_type(3)));
typedef float	t_pointf2 __attribute__((ext_vector_type(2)));
typedef float	t_pointf3 __attribute__((ext_vector_type(3)));
typedef float	t_pointf4 __attribute__((ext_vector_type(4)));

typedef float	t_m3x3 __attribute__((matrix_type(3, 3)));

// typedef struct s_point2D
// {
// 	int	x;
// 	int	y;
// }	t_point2D;

// typedef struct s_point3D
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }	t_point3D;

#endif