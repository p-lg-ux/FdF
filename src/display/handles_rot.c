/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:44:18 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 15:51:11 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
// #include "fdf.h"

void	__handle_rotz_pos(t_data *data)
{
	if (data->map->param.angle_z + ANGLE_UNIT > 2 * M_PI)
		data->map->param.angle_z += (ANGLE_UNIT - 2 * M_PI);
	else
		data->map->param.angle_z += ANGLE_UNIT;
}

void	__handle_rotz_neg(t_data *data)
{
	if (data->map->param.angle_z - ANGLE_UNIT < - (2 * M_PI))
		data->map->param.angle_z -= (ANGLE_UNIT - 2 * M_PI);
	else
		data->map->param.angle_z -= ANGLE_UNIT;
}

void	__handle_roty_pos(t_data *data)
{
	if (data->map->param.angle_y + ANGLE_UNIT > 2 * M_PI)
		data->map->param.angle_y += (ANGLE_UNIT - 2 * M_PI);
	else
		data->map->param.angle_y += ANGLE_UNIT;
}

void	__handle_roty_neg(t_data *data)
{
	if (data->map->param.angle_y - ANGLE_UNIT < - (2 * M_PI))
		data->map->param.angle_y -= (ANGLE_UNIT - 2 * M_PI);
	else
		data->map->param.angle_y -= ANGLE_UNIT;
}

void	__handle_rotx_pos(t_data *data)
{
	if (data->map->param.angle_x + ANGLE_UNIT > 2 * M_PI)
		data->map->param.angle_x += (ANGLE_UNIT - 2 * M_PI);
	else
		data->map->param.angle_x += ANGLE_UNIT;
}
