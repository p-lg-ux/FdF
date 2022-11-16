/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:01:02 by pgros             #+#    #+#             */
/*   Updated: 2022/11/16 19:30:16 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdio.h>

void	__img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	__set_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &handle_leave, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
}

int	__initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Fil de fer");
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->img.mlx_img == NULL)
		return (MLX_ERROR);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &(data->img.bpp),
		&(data->img.line_len), &(data->img.endian));
	return (MLX_INIT_SUCCESS);
}

void	__mlx_display(t_data *data)
{
	int	ret;
	
	ret = __initialize(data);
	if (ret == MLX_ERROR)
	{
		printf("init error"); //TODO : remove printf
		handle_leave(data);
	}
	__set_hooks(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

// void	__free_data_content(t_data *data)
// {
// 	if (data->mlx_ptr != NULL)
// 		free(data->mlx_ptr);
// 	if (data->win_ptr != NULL)
// 		free(data->win_ptr);
// 	if (data->map != NULL)
// 		__free_map(data->map);
// }