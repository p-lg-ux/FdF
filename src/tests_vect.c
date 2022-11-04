/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:48 by pgros             #+#    #+#             */
/*   Updated: 2022/11/04 15:08:01 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// typedef int		t_int2 __attribute__((vector_size(2 * sizeof(int))));
// typedef int		t_int3 __attribute__((vector_size(3 * sizeof(int))));

typedef int		t_int2 __attribute__((ext_vector_type(2)));
typedef int		t_int3 __attribute__((ext_vector_type(3)));
typedef float	t_float2 __attribute__((ext_vector_type(2)));
typedef float	t_float3 __attribute__((ext_vector_type(3)));
typedef float	t_float4 __attribute__((ext_vector_type(4)));

typedef float		t_m3x3 __attribute__((matrix_type(3, 3)));

void	print_m3x3(t_m3x3 mat)
{
	int	r;
	int	c;

	printf("[");
	r = 0;
	while (r < 3)
	{
		c = 0;
		printf("\t");
		while (c < 3)
		{
			printf("%f\t", mat[r][c]);
			c++;
		}
		printf("\n");
		r++;
	}
	printf("]\n\n");
}

void	load_m3x3(t_m3x3 *mat, float vals[9])
{
	int	r;
	int	c;

	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 3)
		{
			(*mat)[r][c] = vals[3*r + c];
			c++;
		}
		r++;
	}
}

// clang -fenable-matrix -Wall -Wextra -Werror -I./include/ ./src/main.c
int	main(int argc, char **argv)
{
	// t_map	*map;
	t_int2		vec_i2;
	t_int3		vec_i3;
	t_int2		a;
	t_int2		b;
	// t_float3	vec_f3;
	t_m3x3		A;
	float		valsA[9] = {1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0};
	float		valsB[9] = {1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0};
	t_m3x3		B;
	
	(void)argv;
	if (argc != 2)
	{
		printf("Error\n");//TODO : change to ft_printf
		// exit(EXIT_FAILURE);
	}
	vec_i2 = (t_int2){1, 2};
	vec_i3 = (t_int3){1, 2, 3};
	printf("i2 : [%i, %i]\n", vec_i2.x, vec_i2.y);
	printf("i3 : [%i, %i, %i]\n", vec_i3.x, vec_i3.y, vec_i3.z);
	a = vec_i2;
	vec_i2 += 1;
	b = vec_i2;
	printf("i2 : [%i, %i]\n", vec_i2.x, vec_i2.y);
	printf("a : [%i, %i]\n", a.x, a.y);
	printf("b : [%i, %i]\n", b.x, b.y);
	a = a * b;
	printf("a : [%i, %i]\n", a.x, a.y);
	load_m3x3(&A, valsA);
	load_m3x3(&B, valsB);
	printf("A =\n");
	print_m3x3(A);
	printf("B =\n");
	print_m3x3(B);
	printf("A * B =\n");
	print_m3x3(A*B);
	printf("B * A =\n");
	print_m3x3(B * A);
	printf("A + B =\n");
	print_m3x3(A + B);
	printf("2 * A =\n");
	print_m3x3(2*A);
	return (0);

}