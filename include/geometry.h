/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:11 by pgros             #+#    #+#             */
/*   Updated: 2022/11/18 18:55:23 by pgros            ###   ########.fr       */
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

# define X_AXIS	0
# define Y_AXIS	1
# define Z_AXIS	2
# define SCALE	3

# define ALPHA	35.26
# define BETA	-45.0

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

typedef struct s_affine
{
	t_rot_matrix	rot_x;
	t_rot_matrix	rot_y;
	t_rot_matrix	rot_z;
	t_rot_matrix	scale_s;
	t_point_i3		translate_t;
} t_affine;

typedef struct s_param
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	scale;
	float	t_x;
	float	t_y;
} t_param;

typedef void	(*t_fill_rotmat_func)(t_rot_matrix *rot_mat);

void			__print_point_i3(t_point_i3 *p);
void			__print_matrix(t_matrix A);
t_rot_matrix	*__new_rot_matrix(int axis, float angle);
void			__matrix_product(t_matrix *res, t_matrix A, t_matrix B);
void			__fill_xrot_mat(t_rot_matrix *rot_mat);
void			__fill_yrot_mat(t_rot_matrix *rot_mat);
void			__fill_zrot_mat(t_rot_matrix *rot_mat);
void			__mat_vect_product(t_matrix mat, t_point_i3 *vect);

#endif