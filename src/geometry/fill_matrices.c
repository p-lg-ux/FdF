/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:43:58 by pgros             #+#    #+#             */
/*   Updated: 2022/11/26 17:45:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "lib42.h"
#include <stdio.h>

void	__fill_xrot_mat(t_matrix *rot_mat, float angle)
{
	(*rot_mat)[0][0] = 1;
	(*rot_mat)[0][1] = 0;
	(*rot_mat)[0][2] = 0;
	(*rot_mat)[0][3] = 0;
	(*rot_mat)[1][0] = 0;
	(*rot_mat)[1][1] = cosf(angle);
	(*rot_mat)[1][2] = -sinf(angle);
	(*rot_mat)[1][3] = 0;
	(*rot_mat)[2][0] = 0;
	(*rot_mat)[2][1] = sinf(angle);
	(*rot_mat)[2][2] = cosf(angle);
	(*rot_mat)[2][3] = 0;
	(*rot_mat)[3][0] = 0;
	(*rot_mat)[3][1] = 0;
	(*rot_mat)[3][2] = 0;
	(*rot_mat)[3][3] = 1;
}

void	__fill_yrot_mat(t_matrix *rot_mat, float angle)
{
	(*rot_mat)[0][0] = cosf(angle);
	(*rot_mat)[0][1] = 0;
	(*rot_mat)[0][2] = sinf(angle);
	(*rot_mat)[0][3] = 0;
	(*rot_mat)[1][0] = 0;
	(*rot_mat)[1][1] = 1;
	(*rot_mat)[1][2] = 0;
	(*rot_mat)[1][3] = 0;
	(*rot_mat)[2][0] = -sinf(angle);
	(*rot_mat)[2][1] = 0;
	(*rot_mat)[2][2] = cosf(angle);
	(*rot_mat)[2][3] = 0;
	(*rot_mat)[3][0] = 0;
	(*rot_mat)[3][1] = 0;
	(*rot_mat)[3][2] = 0;
	(*rot_mat)[3][3] = 1;
}

void	__fill_zrot_mat(t_matrix *rot_mat, float angle)
{
	(*rot_mat)[0][0] = cosf(angle);
	(*rot_mat)[0][1] = -sinf(angle);
	(*rot_mat)[0][2] = 0;
	(*rot_mat)[0][3] = 0;
	(*rot_mat)[1][0] = sinf(angle);
	(*rot_mat)[1][1] = cosf(angle);
	(*rot_mat)[1][2] = 0;
	(*rot_mat)[1][3] = 0;
	(*rot_mat)[2][0] = 0;
	(*rot_mat)[2][1] = 0;
	(*rot_mat)[2][2] = 1;
	(*rot_mat)[2][3] = 0;
	(*rot_mat)[3][0] = 0;
	(*rot_mat)[3][1] = 0;
	(*rot_mat)[3][2] = 0;
	(*rot_mat)[3][3] = 1;
}

void	__fill_scale_mat(t_matrix *scale_mat, float *scale)
{
	(*scale_mat)[0][0] = scale[0];
	(*scale_mat)[0][1] = 0.0;
	(*scale_mat)[0][2] = 0.0;
	(*scale_mat)[0][3] = 0.0;
	(*scale_mat)[1][0] = 0.0;
	(*scale_mat)[1][1] = scale[1];
	(*scale_mat)[1][2] = 0.0;
	(*scale_mat)[1][3] = 0.0;
	(*scale_mat)[2][0] = 0.0;
	(*scale_mat)[2][1] = 0.0;
	(*scale_mat)[2][2] = scale[2];
	(*scale_mat)[2][3] = 0.0;
	(*scale_mat)[3][0] = 0.0;
	(*scale_mat)[3][1] = 0.0;
	(*scale_mat)[3][2] = 0.0;
	(*scale_mat)[3][3] = 1.0;
}

void	__fill_translation_mat(t_matrix *translation_mat, float *t)
{
	(*translation_mat)[0][0] = 1.0;
	(*translation_mat)[0][1] = 0.0;
	(*translation_mat)[0][2] = 0.0;
	(*translation_mat)[0][3] = t[0];
	(*translation_mat)[1][0] = 0.0;
	(*translation_mat)[1][1] = 1.0;
	(*translation_mat)[1][2] = 0.0;
	(*translation_mat)[1][3] = t[1];
	(*translation_mat)[2][0] = 0.0;
	(*translation_mat)[2][1] = 0.0;
	(*translation_mat)[2][2] = 1.0;
	(*translation_mat)[2][3] = t[2];
	(*translation_mat)[3][0] = 0.0;
	(*translation_mat)[3][1] = 0.0;
	(*translation_mat)[3][2] = 0.0;
	(*translation_mat)[3][3] = 1.0;
}
