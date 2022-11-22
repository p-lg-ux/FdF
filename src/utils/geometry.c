/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/22 17:58:47 by pgros            ###   ########.fr       */
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
	rot_mat->mat[0][3] = 0;
	rot_mat->mat[1][0] = 0;
	rot_mat->mat[1][1] = cosf(rot_mat->angle);
	rot_mat->mat[1][2] = -sinf(rot_mat->angle);
	rot_mat->mat[1][3] = 0;
	rot_mat->mat[2][0] = 0;
	rot_mat->mat[2][1] = sinf(rot_mat->angle);
	rot_mat->mat[2][2] = cosf(rot_mat->angle);
	rot_mat->mat[2][3] = 0;
	rot_mat->mat[3][0] = 0;
	rot_mat->mat[3][1] = 0;
	rot_mat->mat[3][2] = 0;
	rot_mat->mat[3][3] = 1;
}

void	__fill_yrot_mat(t_rot_matrix *rot_mat)
{
	rot_mat->mat[0][0] = cosf(rot_mat->angle);
	rot_mat->mat[0][1] = 0;
	rot_mat->mat[0][2] = sinf(rot_mat->angle);
	rot_mat->mat[0][3] = 0;
	rot_mat->mat[1][0] = 0;
	rot_mat->mat[1][1] = 1;
	rot_mat->mat[1][2] = 0;
	rot_mat->mat[1][3] = 0;
	rot_mat->mat[2][0] = -sinf(rot_mat->angle);
	rot_mat->mat[2][1] = 0;
	rot_mat->mat[2][2] = cosf(rot_mat->angle);
	rot_mat->mat[2][3] = 0;
	rot_mat->mat[3][0] = 0;
	rot_mat->mat[3][1] = 0;
	rot_mat->mat[3][2] = 0;
	rot_mat->mat[3][3] = 1;
}

void	__fill_zrot_mat(t_rot_matrix *rot_mat)
{
	rot_mat->mat[0][0] = cosf(rot_mat->angle);
	rot_mat->mat[0][1] = -sinf(rot_mat->angle);
	rot_mat->mat[0][2] = 0;
	rot_mat->mat[0][3] = 0;
	rot_mat->mat[1][0] = sinf(rot_mat->angle);
	rot_mat->mat[1][1] = cosf(rot_mat->angle);
	rot_mat->mat[1][2] = 0;
	rot_mat->mat[1][3] = 0;
	rot_mat->mat[2][0] = 0;
	rot_mat->mat[2][1] = 0;
	rot_mat->mat[2][2] = 1;
	rot_mat->mat[2][3] = 0;
	rot_mat->mat[3][0] = 0;
	rot_mat->mat[3][1] = 0;
	rot_mat->mat[3][2] = 0;
	rot_mat->mat[3][3] = 1;
}

void	__fill_scale_mat(t_scale_matrix *scale_mat)
{
	scale_mat->mat[0][0] = scale_mat->scale[0];
	scale_mat->mat[0][1] = 0.0;
	scale_mat->mat[0][2] = 0.0;
	scale_mat->mat[0][3] = 0.0;
	scale_mat->mat[1][0] = 0.0;
	scale_mat->mat[1][1] = scale_mat->scale[1];
	scale_mat->mat[1][2] = 0.0;
	scale_mat->mat[1][3] = 0.0;
	scale_mat->mat[2][0] = 0.0;
	scale_mat->mat[2][1] = 0.0;
	scale_mat->mat[2][2] = scale_mat->scale[2];
	scale_mat->mat[2][3] = 0.0;
	scale_mat->mat[3][0] = 0.0;
	scale_mat->mat[3][1] = 0.0;
	scale_mat->mat[3][2] = 0.0;
	scale_mat->mat[3][3] = 1.0;
}

void	__fill_translation_mat(t_translation_matrix *translation_mat)
{
	translation_mat->mat[0][0] = 1.0;
	translation_mat->mat[0][1] = 0.0;
	translation_mat->mat[0][2] = 0.0;
	translation_mat->mat[0][3] = translation_mat->translation[0];
	translation_mat->mat[1][0] = 0.0;
	translation_mat->mat[1][1] = 1.0;
	translation_mat->mat[1][2] = 0.0;
	translation_mat->mat[1][3] = translation_mat->translation[1];
	translation_mat->mat[2][0] = 0.0;
	translation_mat->mat[2][1] = 0.0;
	translation_mat->mat[2][2] = 1.0;
	translation_mat->mat[2][3] = translation_mat->translation[2];
	translation_mat->mat[3][0] = 0.0;
	translation_mat->mat[3][1] = 0.0;
	translation_mat->mat[3][2] = 0.0;
	translation_mat->mat[3][3] = 1.0;
}

t_translation_matrix	*__new_translation_matrix(float *translation)
{
	t_translation_matrix *translation_mat;

	translation_mat = malloc(sizeof(t_translation_matrix));
	if (translation_mat == NULL)
		return (NULL);
	translation_mat->translation[0] = translation[0];
	translation_mat->translation[1] = translation[1];
	translation_mat->translation[2] = translation[2];
	__fill_translation_mat(translation_mat);
	// printf("translation matrix =\n");
	// __print_matrix(translation_mat->mat);
	// printf("\n");
	return (translation_mat);
}

t_scale_matrix	*__new_scale_matrix(float *scale)
{
	t_scale_matrix *scale_mat;

	scale_mat = malloc(sizeof(t_scale_matrix));
	if (scale_mat == NULL)
		return (NULL);
	scale_mat->scale[0] = scale[0];
	scale_mat->scale[1] = scale[1];
	scale_mat->scale[2] = scale[2];
	__fill_scale_mat(scale_mat);
	printf("scale matrix =\n");
	__print_matrix(scale_mat->mat);
	printf("\n");
	return (scale_mat);
}

t_rot_matrix	*__new_rot_matrix(int axis, float angle)
{
	t_rot_matrix *rot_mat;
	const t_fill_rotmat_func	fill_rotmat_funcs_map[] = {
	[X_AXIS] = &__fill_xrot_mat,
	[Y_AXIS] = &__fill_yrot_mat,
	[Z_AXIS] = &__fill_zrot_mat,
	};
	
	rot_mat = malloc(sizeof(t_rot_matrix));
	if (rot_mat == NULL)
		return (NULL);
	rot_mat->angle = angle;
	fill_rotmat_funcs_map[axis](rot_mat);
	return (rot_mat);
}

void	__copy_mat(t_matrix *copy, t_matrix original)
{
	int	l;
	int	c;

	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			(*copy)[l][c] = original[l][c];
			c++;
		}
		l++;
	}
}

void	__multiple_mat_product(t_matrix *res, t_matrix **mat_tab)
{
	int			i;
	t_matrix	copy;
	
	if (mat_tab == NULL || *mat_tab == NULL)
		return ;

	printf("mat_tab[0] =\n");
	__print_matrix(*(mat_tab[0]));
	printf("\n");
	
	printf("mat_tab[1] =\n");
	__print_matrix(*(mat_tab[1]));
	printf("\n");
	
	__matrix_product(res, *(mat_tab[1]), *(mat_tab[0]));
	i = 2;
	printf("res =\n");
	__print_matrix(*res);
	printf("\n");
	while (mat_tab[i] != NULL)
	{
		__copy_mat(&copy, *res);
		__matrix_product(res, *(mat_tab[i]), copy);
		printf("res =\n");
		__print_matrix(*res);
		printf("\n");
		i++;
	}
}

void	__matrix_product(t_matrix *res, t_matrix A, t_matrix B)
{
	int	l;
	int	c;
	int	i;

	l = -1;
	while (++l < 4)
	{
		c = -1;
		while (++c < 4)
		{
			(*res)[l][c] = 0;
			i = -1;
			while (++i < 4)
				(*res)[l][c] += A[l][i] * B[i][c];
		}
	}
}

void	__mat_vect_product(t_matrix m, t_point_i3 *vec)
{
	const int	v[3] = {vec->x, vec->y, vec->z};
	
	vec->x = rintf(v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2] + m[0][3]);
	vec->y = rintf(v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2] + m[1][3]);
	vec->z = rintf(v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2] + m[2][3]);
}

void	__print_point_i3(t_point_i3 *p)
{
	printf("[ %i\t%i\t%i ]", p->x , p->y, p->z);
}

void	__print_matrix(t_matrix A)
{
	printf("[\t%f\t%f\t%f\t%f\n", A[0][0], A[0][1], A[0][2], A[0][3]);
	printf("\t%f\t%f\t%f\t%f\n", A[1][0], A[1][1], A[1][2], A[1][3]);
	printf("\t%f\t%f\t%f\t%f\n", A[2][0], A[2][1], A[2][2], A[2][3]);
	printf("\t%f\t%f\t%f\t%f\t]\n", A[3][0], A[3][1], A[3][2], A[3][3]);
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