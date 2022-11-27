/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:05:32 by pgros             #+#    #+#             */
/*   Updated: 2022/11/28 00:34:46 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	__handle_tx_up(t_data *data)
{
	if (fabs(data->map->param.t_x - TRANSLATION_UNIT) < 100 * WINDOW_HEIGHT)
		data->map->param.t_x -= TRANSLATION_UNIT;
}

void	__handle_tx_down(t_data *data)
{
	if (fabs(data->map->param.t_x + TRANSLATION_UNIT) < 100 * WINDOW_HEIGHT)
		data->map->param.t_x += TRANSLATION_UNIT;
}

void	__handle_ty_left(t_data *data)
{
	if (fabs(data->map->param.t_y - TRANSLATION_UNIT) < 100 * WINDOW_WIDTH)
		data->map->param.t_y -= TRANSLATION_UNIT;
}

void	__handle_ty_right(t_data *data)
{
	if (fabs(data->map->param.t_y + TRANSLATION_UNIT) < 100 * WINDOW_WIDTH)
		data->map->param.t_y += TRANSLATION_UNIT;
}
