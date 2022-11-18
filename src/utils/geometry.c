/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/18 18:09:00 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "lib42.h"
#include <stdio.h>

void	__fill_xrot_mat(t_rot_matrix *rot_mat)
{
	rot_mat->mat[0][0] = 1;
	rot_mat->mat[0][1] = 0;
	rot_mat->mat[0][2] = 0;
	rot_mat->mat[1][0] = 0;
	rot_mat->mat[1][1] = cosf(rot_mat->angle);
	rot_mat->mat[1][2] = -sinf(rot_mat->angle);
	rot_mat->mat[2][0] = 0;
	rot_mat->mat[2][1] = sinf(rot_mat->angle);
	rot_mat->mat[2][2] = cosf(rot_mat->angle);
}

void	__fill_yrot_mat(t_rot_matrix *rot_mat)
{
	rot_mat->mat[0][0] = cosf(rot_mat->angle);
	rot_mat->mat[0][1] = 0;
	rot_mat->mat[0][2] = sinf(rot_mat->angle);
	rot_mat->mat[1][0] = 0;
	rot_mat->mat[1][1] = 1;
	rot_mat->mat[1][2] = 0;
	rot_mat->mat[2][0] = -sinf(rot_mat->angle);
	rot_mat->mat[2][1] = 0;
	rot_mat->mat[2][2] = cosf(rot_mat->angle);
}

void	__fill_zrot_mat(t_rot_matrix *rot_mat)
{
	rot_mat->mat[0][0] = cosf(rot_mat->angle);
	rot_mat->mat[0][1] = -sinf(rot_mat->angle);
	rot_mat->mat[0][2] = 0;
	rot_mat->mat[1][0] = sinf(rot_mat->angle);
	rot_mat->mat[1][1] = cosf(rot_mat->angle);
	rot_mat->mat[1][2] = 0;
	rot_mat->mat[2][0] = 0;
	rot_mat->mat[2][1] = 0;
	rot_mat->mat[2][2] = 1;
}

void	__fill_scale_mat(t_rot_matrix *scale_mat)
{
	scale_mat->mat[0][0] = scale_mat->angle;
	scale_mat->mat[0][1] = 0;
	scale_mat->mat[0][2] = 0;
	scale_mat->mat[1][0] = 0;
	scale_mat->mat[1][1] = scale_mat->angle;
	scale_mat->mat[1][2] = 0;
	scale_mat->mat[2][0] = 0;
	scale_mat->mat[2][1] = 0;
	scale_mat->mat[2][2] = scale_mat->angle;
}

t_rot_matrix	*__new_rot_matrix(int axis, float angle)
{
	t_rot_matrix *rot_mat;
	const t_fill_rotmat_func	fill_rotmat_funcs_map[] = {
	[X_AXIS] = &__fill_xrot_mat,
	[Y_AXIS] = &__fill_yrot_mat,
	[Z_AXIS] = &__fill_zrot_mat,
	[SCALE] = &__fill_scale_mat,
	};
	
	rot_mat = malloc(sizeof(t_rot_matrix));
	if (rot_mat == NULL)
		return (NULL);
	rot_mat->angle = angle;
	fill_rotmat_funcs_map[axis](rot_mat);
	return (rot_mat);
}

void	__matrix_product(t_matrix *res, t_matrix A, t_matrix B)
{
	int	l;
	int	c;
	int	i;

	l = -1;
	while (++l < 3)
	{
		c = -1;
		while (++c < 3)
		{
			(*res)[l][c] = 0;
			i = -1;
			while (++i < 3)
				(*res)[l][c] += A[l][i] * B[i][c];
		}
	}
}

void	__mat_vect_product(t_matrix mat, t_point_i3 *vect)
{
	const int	v[3] = {vect->x, vect->y, vect->z};
	
	vect->x = rintf(v[0] * mat[0][0] + v[1] * mat[0][1] + v[2] * mat[0][2]);
	vect->y = rintf(v[0] * mat[1][0] + v[1] * mat[1][1] + v[2] * mat[1][2]);
	vect->z = rintf(v[0] * mat[2][0] + v[1] * mat[2][1] + v[2] * mat[2][2]);
}

void	__print_point_i3(t_point_i3 *p)
{
	printf("[ %i\t%i\t%i ]", p->x , p->y, p->z);
}

void	__print_matrix(t_matrix A)
{
	printf("[\t%f\t%f\t%f\n", A[0][0], A[0][1], A[0][2]);
	printf("\t%f\t%f\t%f\n", A[1][0], A[1][1], A[1][2]);
	printf("\t%f\t%f\t%f\t]\n", A[2][0], A[2][1], A[2][2]);
}

// int main(void)
// {
// 	// int	i;
// 	t_matrix A = {{0.33, 0.33, 0.33}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0}};
// 	t_matrix B = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};
// 	t_matrix C;
// 	t_point_i3 v;
	
// 	printf("A =\n");
// 	__print_matrix(A);
// 	printf("\n");
// 	printf("B =\n");
// 	__print_matrix(B);
// 	printf("\n");

// 	__matrix_product(&C, B, A);
// 	printf("C =\n");
// 	__print_matrix(C);
// 	printf("\n");

// 	v.x = 1;
// 	v.y = 1;
// 	v.z = 1;

// 	printf("v =\n");
// 	__print_point_i3(&v);
// 	printf("\n\n");

// 	__mat_vect_product(A, &v);
// 	printf("A * v =\n");
// 	__print_point_i3(&v);
// 	printf("\n\n");
	
// 	return(0);
// }