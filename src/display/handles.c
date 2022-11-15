/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:58:53 by pgros             #+#    #+#             */
/*   Updated: 2022/11/15 19:21:31 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "stdio.h"
#include "unistd.h"

int	handle_no_event(t_data *data)
{
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_leave(t_data *data)
{
	// printf("Leave 2\n");
	printf("data = %p\n", data);
	printf("data->mlx_ptr = %p\n", data->mlx_ptr);
	printf("data->win_ptr = %p\n", data->win_ptr);
	// printf("data->im.mlx_img = %p\n", data->img.mlx_img);
	// printf("data->im = %p\n", &(data->img));
	//mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	// __free_map(data->map);
	exit (0);
	return (0);
}