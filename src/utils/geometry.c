/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/17 18:35:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <stdio.h>

t_rot_matrix	*__new_rot_matrix(int axis, float angle)
{
	t_rot_matrix *rot_mat;
	
	rot_mat = ft_calloc(1, sizeof(t_rot_matrix));
	if (rot_mat == NULL)
		return (NULL);
	rot_mat->angle = angle;
	//TODO : instantiate the mat attribute of rot_mat according to the axis.
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
// 	int	i;
// 	t_matrix A = {{1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0}};
// 	t_matrix B = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};
// 	t_matrix C;
	
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

// 	return(0);
// }