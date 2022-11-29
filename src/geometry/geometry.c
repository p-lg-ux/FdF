/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 19:24:30 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
// #include "fdf.h"
#include "lib42.h"
#include <stdio.h>

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
	__matrix_product(res, *(mat_tab[1]), *(mat_tab[0]));
	i = 2;
	while (mat_tab[i] != NULL && i < 8)
	{
		__copy_mat(&copy, *res);
		__matrix_product(res, *(mat_tab[i]), copy);
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

void	__mat_vect_res_product(t_matrix m, t_point_i3 vec, t_point_i3 *res)
{
	const int	v[3] = {vec.x, vec.y, vec.z};

	if (res == NULL)
		return ;
	res->x = rintf(v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2] + m[0][3]);
	res->y = rintf(v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2] + m[1][3]);
	res->z = rintf(v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2] + m[2][3]);
}

// void	__print_point_i3(t_point_i3 *p)
// {
// 	ft_printf("[ %i\t%i\t%i ]", p->x , p->y, p->z);
// }
// 
// void	__print_matrix(t_matrix A)
// {
// 	printf("[\t%f\t%f\t%f\t%f\n", A[0][0], A[0][1], A[0][2], A[0][3]);
// 	printf("\t%f\t%f\t%f\t%f\n", A[1][0], A[1][1], A[1][2], A[1][3]);
// 	printf("\t%f\t%f\t%f\t%f\n", A[2][0], A[2][1], A[2][2], A[2][3]);
// 	printf("\t%f\t%f\t%f\t%f\t]\n", A[3][0], A[3][1], A[3][2], A[3][3]);
// }
