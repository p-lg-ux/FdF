/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:51:20 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 16:05:27 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
// #include "fdf.h"

void	__handle_rotx_neg(t_data *data)
{
	if (data->map->param.angle_x - ANGLE_UNIT < - (2 * M_PI))
		data->map->param.angle_x -= (ANGLE_UNIT - 2 * M_PI);
	else
		data->map->param.angle_x -= ANGLE_UNIT;
}

void	__handle_zoom_pos(t_data *data)
{
	if (data->map->param.scale + SCALE_UNIT < 200)
		data->map->param.scale += SCALE_UNIT;
}

void	__handle_zoom_neg(t_data *data)
{
	if (data->map->param.scale - SCALE_UNIT > 0.000001)
		data->map->param.scale -= SCALE_UNIT;
}
