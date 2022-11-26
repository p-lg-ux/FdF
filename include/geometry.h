/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:54:11 by pgros             #+#    #+#             */
/*   Updated: 2022/11/26 17:50:08 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <math.h>
# include <stdlib.h>

# define X_AXIS	0
# define Y_AXIS	1
# define Z_AXIS	2

# define ALPHA				-0.610865
# define BETA				-0.785398

# define ANGLE_UNIT			0.0872665
# define SCALE_UNIT			0.1
# define TRANSLATION_UNIT	10

typedef	float	t_matrix[4][4];

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

typedef struct s_scale_matrix
{
	float		scale[3];
	t_matrix	mat;
} t_scale_matrix;

typedef struct s_translation_matrix
{
	float		translation[3];
	t_matrix	mat;
} t_translation_matrix;

typedef struct s_mat_tab
{
	t_matrix			rot_x;
	t_matrix			rot_y;
	t_matrix			rot_z;
	t_matrix			scale_s;
	t_matrix			iso_z;
	t_matrix			iso_y;
	t_matrix			translate_t;
} t_mat_tab;

typedef struct s_param
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	scale;
	float	t_x;
	float	t_y;
} t_param;

typedef void	(*t_fill_rotmat_func)(t_matrix *rot_mat, float angle);

// void			__print_point_i3(t_point_i3 *p);
// void			__print_matrix(t_matrix A);
t_rot_matrix	*__new_rot_matrix(int axis, float angle);
t_scale_matrix	*__new_scale_matrix(float *scale);
t_translation_matrix	*__new_translation_matrix(float *translation);
void			__matrix_product(t_matrix *res, t_matrix A, t_matrix B);
void			__fill_rot_mat(t_matrix *rot_mat, int axis, float angle);
void			__fill_xrot_mat(t_matrix *rot_mat, float angle);
void			__fill_yrot_mat(t_matrix *rot_mat, float angle);
void			__fill_zrot_mat(t_matrix *rot_mat, float angle);
void			__fill_scale_mat(t_matrix *scale_mat, float *scale);
void			__fill_translation_mat(t_matrix *translation_mat, float *t);
void			__mat_vect_product(t_matrix m, t_point_i3 *vec);
void			__mat_vect_res_product(t_matrix mat, t_point_i3 vec, t_point_i3 *res);
void			__multiple_mat_product(t_matrix *res, t_matrix *mat_tab[]);

#endif