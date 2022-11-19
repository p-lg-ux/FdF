/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:25:46 by pgros             #+#    #+#             */
/*   Updated: 2022/11/19 17:33:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	degrade_color(int begin, int end, int i, int step)
{
	t_color	*t_begin;
	t_color	*t_end;
	t_color	t_ret;
	float	dR;
	float	dG;
	float	dB;

	t_begin = to_t_color(begin);
	t_end = to_t_color(end);
	//TODO : bouger ce calcul dans la fonction __trace_segment
	/*
	dR = t_end->R - t_begin->R;
	dG = t_end->G - t_begin->G;
	dB = t_end->B - t_begin->B;*/
	t_ret.R = t_begin->R + ((int) ((dR * i) / step));
	t_ret.G = t_begin->G + ((int) ((dG * i) / step));
	t_ret.B = t_begin->B + ((int) ((dB * i) / step));
	free(t_begin);
	free(t_end);
	return (to_val(t_ret));
}

void	__trace_segment(t_data *data, t_lstmap *A, t_lstmap *B)
{
	int	step;
	float	dx;
	float	dy;
	float	x;
	float	y;
	int	i;
	int	begin = COLOR_MAX;
	int end	= COLOR_MIN;
	
	A = data->A;
	B = data->B;
	dx = (float) (B.x - A.x);
	dy = (float) (B.y - A.y);
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	i = 0;
	x = A.x;
	y = A.y;
	printf("Range = %d\n", end - begin);
	while (i < step)
	{
		img_pix_put(&(data->img), x, y, degrade_color(begin, end, i, step));
		x += dx;
		y += dy;
		i++;
	}
}