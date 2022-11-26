/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/26 17:24:09 by pgros            ###   ########.fr       */
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
		return (__quit(data, EXIT_FAILURE, NULL));
	translate = __new_translation_matrix((float *)translate_v);
	if (translate == NULL)
		return (free(scale), __quit(data, EXIT_FAILURE, NULL));
	__multiple_mat_product(&affine, (t_matrix *[]){
		&(translate->mat), &(scale->mat), NULL});
	__apply_transform_to_map(data, &affine);
	free(scale);
	free(translate);
}

void	__set_isometric_projection(t_map *map)
{
	__fill_rot_mat(&(map->mat_tab.iso_z), Z_AXIS, BETA);
	__fill_rot_mat(&(map->mat_tab.iso_y), Y_AXIS, ALPHA);
}

void	__set_map_transform(t_map *map)
{
	const float	s[3] = {map->param.scale, map->param.scale, map->param.scale};
	const float t[3] = {map->param.t_x, map->param.t_y, 0};
	
	__fill_rot_mat(&(map->mat_tab.rot_x), X_AXIS, map->param.angle_x);
	__fill_rot_mat(&(map->mat_tab.rot_y), Y_AXIS, map->param.angle_y);
	__fill_rot_mat(&(map->mat_tab.rot_z), Z_AXIS, map->param.angle_z);
	__fill_scale_mat(&(map->mat_tab.scale_s), (float *) s);
	__fill_translation_mat(&(map->mat_tab.translate_t), (float *) t);
	__multiple_mat_product(&(map->transform), (t_matrix *[]){
		&(map->mat_tab.rot_x),
		&(map->mat_tab.rot_y),
		&(map->mat_tab.rot_z),
		&(map->mat_tab.scale_s),
		&(map->mat_tab.iso_z),
		&(map->mat_tab.iso_y),
		&(map->mat_tab.translate_t),
		NULL});
}

void	__put_map_to_im(t_data *data)
{
	t_lstmap *node;

	__reset_background(data);
	__set_map_transform(data->map);
	__apply_transform(data, &(data->map->transform));
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
