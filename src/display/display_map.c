/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/25 17:56:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdio.h>

void	__apply_transform_to_map(t_data *data, t_matrix *transform)
{
	t_lstmap	*node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_product(*transform, node->point3D);
		node = node->next;
	}
}

void	__apply_transform(t_data *data, t_matrix *transform)
{
	t_lstmap	*node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_res_product(*transform, *(node->point3D),
			&(node->transformed));
		node = node->next;
	}
}

void	__center_scale(t_data *data)
{
	t_scale_matrix			*scale;
	t_translation_matrix	*translate;
	t_matrix				affine;
	float					scale_v[3];
	const float				translate_v[3] = {
		- (data->map->nb_lines / 2),
		- (data->map->nb_columns / 2), 0.0};

	scale_v[0] = fminf(WINDOW_HEIGHT / (data->map->nb_lines * 2.0),
			WINDOW_WIDTH / (data->map->nb_columns * 2.0));
	scale_v[1] = scale_v[0];
	scale_v[2] = scale_v[0] * (fminf(data->map->nb_lines,
				data->map->nb_columns) / (2 * (data->map->range + 1)));
	scale = __new_scale_matrix((float *)scale_v);
	if (scale == NULL)
		return (__quit(data, EXIT_FAILURE));
	translate = __new_translation_matrix((float *)translate_v);
	if (translate == NULL)
		return (free(scale), __quit(data, EXIT_FAILURE));
	__multiple_mat_product(&affine, (t_matrix *[]){
		&(translate->mat), &(scale->mat), NULL});
	__apply_transform_to_map(data, &affine);
	free(scale);
	free(translate);
}

void	__isometric_projection(t_data *data)
{
	const float		center_v[3] = {WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, 0.0};

	t_matrix		*mat_tab[6];
	t_matrix		affine;
	t_rot_matrix	*rot_z;
	t_rot_matrix	*rot_y;
	t_translation_matrix *center;

	rot_z = __new_rot_matrix(Z_AXIS, BETA);
	if (rot_z == NULL)
		return ;
	rot_y = __new_rot_matrix(Y_AXIS, ALPHA);
	if (rot_y == NULL)
		return (free(rot_z));
	center = __new_translation_matrix((float *)center_v);
	if (center == NULL)
		return (free(rot_z), free(rot_y));
	// printf("translate =\n");
	// __print_matrix(translate->mat);
	// printf("\n");
	// printf("scale =\n");
	// __print_matrix(scale->mat);
	// printf("\n");
	mat_tab[0] = &(rot_z->mat);
	mat_tab[1] = &(rot_y->mat);
	// mat_tab[4] = &(center->mat);
	// mat_tab[5] = NULL;
	mat_tab[2] = NULL;

	// printf("z angle = %f\n y angle = %f\n", rot_z->angle, rot_y->angle);
	// __matrix_product(&tmp, rot_y->mat, rot_z->mat);
	// printf("tmp =\n");
	// __print_matrix(tmp);
	// printf("\n");
	// __matrix_product(&affine, tmp, scale->mat);
	// affine = &(scale->mat);
	__multiple_mat_product(&affine, (t_matrix **)mat_tab);
	// printf("affine =\n");
	// __print_matrix(affine);
	// printf("\n");
	__apply_transform_to_map(data, &affine);
	free(rot_z);
	free(rot_y);
	free(center);
}

void	__put_map_to_im(t_data *data)
{
	t_lstmap *node;

	__reset_background(data);
	node = data->map->lstmap;
	while (node != NULL)
	{
		if (node->right != NULL)
			__trace_segment(data, node, node->right);
		if (node->down != NULL)
			__trace_segment(data, node, node->down);
		node = node->next;
	}
}
