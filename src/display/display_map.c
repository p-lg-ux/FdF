/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/22 19:14:13 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdio.h>

void	__apply_transform_to_map(t_data *data, t_matrix *transform)
{
	t_lstmap *node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_product(*transform, node->point3D);
		// node->point3D->x += translation->x;
		// node->point3D->y += translation->y;
		// node->point3D->z += translation->z;
		node = node->next;
	}
}

void	__isometric_projection(t_data *data)
{
	const float		translate_v[3] = {-(data->map->nb_lines/2), -(data->map->nb_columns/2), 0.0};
	const float		center_v[3] = {WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, 0.0};
	const float		s = fminf(WINDOW_HEIGHT / (data->map->nb_lines * 2.0), WINDOW_WIDTH / (data->map->nb_columns * 2.0));
	const float		scale_v[3] = {s, s, s / 2.0};
	t_matrix		*mat_tab[6];
	t_matrix		affine;
	t_translation_matrix *translate;
	t_rot_matrix	*rot_z;
	t_rot_matrix	*rot_y;
	t_scale_matrix	*scale;
	t_translation_matrix *center;

	rot_z = __new_rot_matrix(Z_AXIS, BETA);
	if (rot_z == NULL)
		return ;
	rot_y = __new_rot_matrix(Y_AXIS, ALPHA);
	if (rot_y == NULL)
		return (free(rot_z));
	scale = __new_scale_matrix((float *)scale_v);
	if (scale == NULL)
		return (free(rot_z), free(rot_y));
	translate = __new_translation_matrix((float *)translate_v);
	if (translate == NULL)
		return (free(scale), free(rot_z), free(rot_y));
	center = __new_translation_matrix((float *)center_v);
	if (center == NULL)
		return (free(translate),free(scale), free(rot_z), free(rot_y));
	// printf("translate =\n");
	// __print_matrix(translate->mat);
	// printf("\n");
	// printf("scale =\n");
	// __print_matrix(scale->mat);
	// printf("\n");
	mat_tab[0] = &(translate->mat);
	mat_tab[1] = &(scale->mat);
	mat_tab[2] = &(rot_z->mat);
	mat_tab[3] = &(rot_y->mat);
	mat_tab[4] = &(center->mat);
	mat_tab[5] = NULL;
	
	printf("z angle = %f\n y angle = %f\n", rot_z->angle, rot_y->angle);
	// __matrix_product(&tmp, rot_y->mat, rot_z->mat);
	// printf("tmp =\n");
	// __print_matrix(tmp);
	// printf("\n");
	// __matrix_product(&affine, tmp, scale->mat);
	// affine = &(scale->mat);
	__multiple_mat_product(&affine, (t_matrix **)mat_tab);
	printf("affine =\n");
	__print_matrix(affine);
	printf("\n");
	__apply_transform_to_map(data, &affine);
	free(rot_z);
	free(rot_y);
	free(scale);
	free(translate);
	free(center);
}

void	__put_map_to_im(t_data *data)
{
	t_lstmap *node;

	node = data->map->lstmap;
	// printf("data->img = %p\n", &(data->img));
	while (node != NULL)
	{
		// printf("x = %i\t y = %i\tcolor = %X\n", node->point3D->x, node->point3D->y, node->color->val);
		__img_pix_put(&(data->img), node->point3D->y, node->point3D->x, node->color->val);
		if (node->right != NULL)
			__trace_segment(data, node, node->right);
		if (node->down != NULL)
			__trace_segment(data, node, node->down);
		node = node->next;
	}
}