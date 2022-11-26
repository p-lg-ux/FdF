/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:58:53 by pgros             #+#    #+#             */
/*   Updated: 2022/11/26 17:10:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "stdio.h"
#include "unistd.h"

//TODO : check if pointers are not null before destroying or freeing
void	__quit(t_data *data, int exit_code, char *message)
{
	if (message != NULL)
		perror(message);
	if (data != NULL)
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
	}
	exit (exit_code); 
	return ;
}

int	handle_no_event(t_data *data)
{
	return (0);
}

int	handle_leave(t_data *data)
{
	__quit(data, EXIT_SUCCESS, NULL);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		handle_leave(data);
		return (0);
	}
	// if (keysym == XK_space)
	// {
	// 	__put_map_to_im(data);
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	// 	return (0);
	// }
	if (keysym == XK_o)
	{
		data->map->param.angle_z += ANGLE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_l)
	{
		data->map->param.angle_z -= ANGLE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_i)
	{
		data->map->param.angle_y += ANGLE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_k)
	{
		data->map->param.angle_y -= ANGLE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_u)
	{
		data->map->param.angle_x += ANGLE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_j)
	{
		data->map->param.angle_x -= ANGLE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_KP_Add)
	{
		data->map->param.scale += SCALE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_KP_Subtract)
	{
		data->map->param.scale -= SCALE_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_Up)
	{
		data->map->param.t_x -= TRANSLATION_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_Down)
	{
		data->map->param.t_x += TRANSLATION_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_Right)
	{
		data->map->param.t_y += TRANSLATION_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_Left)
	{
		data->map->param.t_y -= TRANSLATION_UNIT;
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	return (0);
}
