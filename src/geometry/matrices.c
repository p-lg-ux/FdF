/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:46:53 by pgros             #+#    #+#             */
/*   Updated: 2022/11/26 17:47:34 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "lib42.h"
#include <stdio.h>

void	__fill_rot_mat(t_matrix *rot_mat, int axis, float angle)
{
	const t_fill_rotmat_func	fill_rotmat_funcs_map[] = {
	[X_AXIS] = &__fill_xrot_mat,
	[Y_AXIS] = &__fill_yrot_mat,
	[Z_AXIS] = &__fill_zrot_mat,
	};

	fill_rotmat_funcs_map[axis](rot_mat, angle);
}

t_translation_matrix	*__new_translation_matrix(float *translation)
{
	t_translation_matrix	*translation_mat;

	translation_mat = malloc(sizeof(t_translation_matrix));
	if (translation_mat == NULL)
		return (NULL);
	translation_mat->translation[0] = translation[0];
	translation_mat->translation[1] = translation[1];
	translation_mat->translation[2] = translation[2];
	__fill_translation_mat(&(translation_mat->mat), translation);
	return (translation_mat);
}

t_scale_matrix	*__new_scale_matrix(float *scale)
{
	t_scale_matrix	*scale_mat;

	scale_mat = malloc(sizeof(t_scale_matrix));
	if (scale_mat == NULL)
		return (NULL);
	scale_mat->scale[0] = scale[0];
	scale_mat->scale[1] = scale[1];
	scale_mat->scale[2] = scale[2];
	__fill_scale_mat(&(scale_mat->mat), scale);
	return (scale_mat);
}

t_rot_matrix	*__new_rot_matrix(int axis, float angle)
{
	t_rot_matrix	*rot_mat;

	rot_mat = malloc(sizeof(t_rot_matrix));
	if (rot_mat == NULL)
		return (NULL);
	rot_mat->angle = angle;
	__fill_rot_mat(&(rot_mat->mat), axis, angle);
	return (rot_mat);
}
