/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/21 14:00:30 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdio.h>

//TODO : ajouter un vecteur de translation
void	__apply_transform_to_map(t_data *data, t_matrix *transform, t_point_i3 *translation)
{
	t_lstmap *node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_product(*transform, node->point3D);
		node->point3D->x += translation->x;
		node->point3D->y += translation->y;
		node->point3D->z += translation->z;
		node = node->next;
	}
}

//TODO : tester les combinaisons de rotation et ajouter une tranlation pour centrer l'affichage des tests
void	__isometric_projection(t_data *data)
{
	const int		translate[3] = {WINDOW_HEIGHT/2, WINDOW_WIDTH/2, 0};
	t_matrix		tmp;
	t_matrix		affine;
	t_rot_matrix	*rot_z;
	t_rot_matrix	*rot_y;
	t_rot_matrix	*scale;


	rot_z = __new_rot_matrix(Z_AXIS, BETA);
	if (rot_z == NULL)
		return ;
	rot_y = __new_rot_matrix(Y_AXIS, ALPHA);
	// rot_y = __new_rot_matrix(Y_AXIS, -atanf(sqrtf(2.0)/2.0));
	if (rot_y == NULL)
		return (free(rot_z));
	scale = __new_rot_matrix(SCALE, 20.0);
	if (scale == NULL)
		return (free(rot_z), free(rot_y));
	printf("z angle = %f\n y angle = %f\n", rot_z->angle, rot_y->angle);
	__matrix_product(&tmp, rot_y->mat, rot_z->mat);
	printf("tmp =\n");
	__print_matrix(tmp);
	printf("\n");
	__matrix_product(&affine, tmp, scale->mat);
	// affine = &(scale->mat);
	printf("affine =\n");
	__print_matrix(affine);
	printf("\n");
	__apply_transform_to_map(data, &affine, (t_point_i3 *)(translate));
	free(rot_z);
	free(rot_y);
	free(scale);
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