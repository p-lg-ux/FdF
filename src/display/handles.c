/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:58:53 by pgros             #+#    #+#             */
/*   Updated: 2022/11/24 17:49:01 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "stdio.h"
#include "unistd.h"

//TODO : check if pointers are not null before destroying or freeing
void	__quit(t_data *data, int exit_code)
{
	if (data->mlx_ptr != NULL)
	{
		if (data->img.mlx_img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		if (data->win_ptr != NULL)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);	
	}
	__free_map(data->map);
	exit (exit_code); 
	return ;
}

void	__rotate_map(t_data *data, int axis, float angle)
{
	t_rot_matrix *rot_mat;

	rot_mat = __new_rot_matrix(axis, angle);
	if (rot_mat == NULL)
		return ;
	__apply_transform_to_map(data, &(rot_mat->mat));
	free (rot_mat);
}

int	handle_no_event(t_data *data)
{
	return (0);
}

int	handle_leave(t_data *data)
{
	__quit(data, EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		handle_leave(data);
		return (0);
	}
	if (keysym == XK_space)
	{
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_o)
	{
		__rotate_map(data, Z_AXIS, 0.0872665);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_l)
	{
		__rotate_map(data, Z_AXIS, -0.0872665);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_i)
	{
		__rotate_map(data, Y_AXIS, 0.0872665);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_k)
	{
		__rotate_map(data, Y_AXIS, -0.0872665);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_u)
	{
		__rotate_map(data, X_AXIS, 0.0872665);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_j)
	{
		__rotate_map(data, X_AXIS, -0.0872665);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	return (0);
}
