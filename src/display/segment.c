/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:25:46 by pgros             #+#    #+#             */
/*   Updated: 2022/11/27 16:22:07 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__degrade_color(t_color *begin, const float dRGB[3], int i, int step)
{
	t_color	t_ret;

	t_ret.R = begin->R + ((int)((dRGB[0] * i) / step));
	t_ret.G = begin->G + ((int)((dRGB[1] * i) / step));
	t_ret.B = begin->B + ((int)((dRGB[2] * i) / step));
	return (to_val(t_ret));
}

void	__set_step(int *step, float dxy[2])
{
	if (fabs(dxy[0]) > fabs(dxy[1]))
		*step = fabs(dxy[0]);
	else
		*step = fabs(dxy[1]);
}

void	__trace_segment(t_data *data, t_lstmap *A, t_lstmap *B)
{
	const float	drgb[3] = {B->color->R - A->color->R,
		B->color->G - A->color->G, B->color->B - A->color->B};
	int			step;
	float		xy[2];
	float		dxy[2];
	int			i;

	dxy[0] = (float)(B->transformed.x - A->transformed.x);
	dxy[1] = (float)(B->transformed.y - A->transformed.y);
	__set_step(&step, dxy);
	if (step == 0)
		return ;
	dxy[0] = dxy[0] / step;
	dxy[1] = dxy[1] / step;
	i = 0;
	xy[0] = A->transformed.x + (WINDOW_HEIGHT / 2);
	xy[1] = A->transformed.y + (WINDOW_WIDTH / 2);
	while (i < step)
	{
		__img_pix_put(&(data->img), xy[1], xy[0],
			__degrade_color(A->color, drgb, i, step));
		xy[0] += dxy[0];
		xy[1] += dxy[1];
		i++;
	}
}
