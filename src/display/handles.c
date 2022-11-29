/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:58:53 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 15:51:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
// #include "fdf.h"
#include "stdio.h"
#include "unistd.h"

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
	exit(exit_code);
	return ;
}

int	handle_no_event(t_data *data)
{
	(void)data;
	return (0);
}

int	handle_leave(t_data *data)
{
	__quit(data, EXIT_SUCCESS, NULL);
	return (0);
}

int	__is_in_keys(int keysym)
{
	int			i;
	const int	keys[12] = {XK_o, XK_l, XK_i, XK_k, XK_u, XK_j,
		XK_KP_Add, XK_KP_Subtract, XK_Up, XK_Down, XK_Left, XK_Right};

	i = 0;
	while (i < 12)
	{
		if (keysym == keys[i])
			return (1);
		i++;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	const t_ft_key_handle	handles_map[] = {
	[XK_o] = &__handle_rotz_pos, [XK_l] = &__handle_rotz_neg,
	[XK_i] = &__handle_roty_pos, [XK_k] = &__handle_roty_neg,
	[XK_u] = &__handle_rotx_pos, [XK_j] = &__handle_rotx_neg,
	[XK_KP_Add] = &__handle_zoom_pos, [XK_KP_Subtract] = &__handle_zoom_neg,
	[XK_Up] = &__handle_tx_up, [XK_Down] = &__handle_tx_down,
	[XK_Left] = &__handle_ty_left, [XK_Right] = &__handle_ty_right,
	};

	if (keysym == XK_Escape)
	{
		handle_leave(data);
		return (0);
	}
	if (__is_in_keys(keysym) == 1)
	{
		handles_map[keysym](data);
		__put_map_to_im(data);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, 0, 0);
		return (0);
	}
	return (0);
}
