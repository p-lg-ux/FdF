/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:34:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/18 18:57:00 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdio.h>

//TODO : ajouter un vecteur de translation
void	__apply_transform_to_map(t_data *data, t_matrix *transform)
{
	t_lstmap *node;

	node = data->map->lstmap;
	while (node != NULL)
	{
		__mat_vect_product(*transform, node->point3D);
		node = node->next;
	}
}

//TODO : tester les combinaisons de rotation et ajouter une tranlation pour centrer l'affichage des tests
void	__isometric_projection(t_data *data)
{
	t_matrix		tmp;
	t_matrix		affine;
	t_rot_matrix	*rot_z;
	t_rot_matrix	*rot_y;
	t_rot_matrix	*scale;


	rot_z = __new_rot_matrix(Z_AXIS, BETA);
	if (rot_z == NULL)
		return ;
	rot_y = __new_rot_matrix(X_AXIS, ALPHA);
	if (rot_y == NULL)
		return (free(rot_z));
	scale = __new_rot_matrix(SCALE, 10.0);
	if (scale == NULL)
		return (free(rot_z), free(rot_y));
	__matrix_product(&tmp, rot_z->mat, rot_y->mat);
	printf("tmp =\n");
	__print_matrix(tmp);
	printf("\n");
	__matrix_product(&affine, scale->mat, tmp);
	// affine = &(scale->mat);
	printf("affine =\n");
	__print_matrix(affine);
	printf("\n");
	__apply_transform_to_map(data, &affine);
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
		node = node->next;
	}
}