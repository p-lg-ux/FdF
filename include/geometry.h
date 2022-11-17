/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:11 by pgros             #+#    #+#             */
/*   Updated: 2022/11/17 18:24:53 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <math.h>
# include <stdlib.h>

// typedef int		t_int2 __attribute__((vector_size(2 * sizeof(int))));
// typedef int		t_int3 __attribute__((vector_size(3 * sizeof(int))));

// typedef int		t_pointi2 __attribute__((ext_vector_type(2)));
// typedef int		t_pointi3 __attribute__((ext_vector_type(3)));
// typedef float	t_pointf2 __attribute__((ext_vector_type(2)));
// typedef float	t_pointf3 __attribute__((ext_vector_type(3)));
// typedef float	t_pointf4 __attribute__((ext_vector_type(4)));

// typedef float	t_m3x3 __attribute__((matrix_type(3, 3)));

// typedef struct s_point2D
// {
// 	int	x;
// 	int	y;
// }	t_point2D;

# define X_AXIS	0;
# define Y_AXIS	1;
# define Z_AXIS	2;

typedef	float	t_matrix[3][3];

typedef struct s_point_i3
{
	int	x;
	int	y;
	int	z;
}	t_point_i3;

typedef struct s_rot_matrix
{
	float		angle;
	t_matrix	mat;
} t_rot_matrix;

void			__print_point_i3(t_point_i3 *p);
t_rot_matrix	*__new_rot_matrix(int axis, float angle);
void			__matrix_product(t_matrix *res, t_matrix A, t_matrix B);

#endif