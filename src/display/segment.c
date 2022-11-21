/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:25:46 by pgros             #+#    #+#             */
/*   Updated: 2022/11/21 13:44:39 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__degrade_color(t_color *begin, const float dRGB[3], int i, int step)
{
	t_color	t_ret;
	// float	dR;
	// float	dG;
	// float	dB;

	//TODO : bouger ce calcul dans la fonction __trace_segment
	/*
	dR = t_end->R - t_begin->R;
	dG = t_end->G - t_begin->G;
	dB = t_end->B - t_begin->B;*/
	t_ret.R = begin->R + ((int) ((dRGB[0] * i) / step));
	t_ret.G = begin->G + ((int) ((dRGB[1] * i) / step));
	t_ret.B = begin->B + ((int) ((dRGB[2] * i) / step));
	// free(t_begin);
	// free(t_end);
	return (to_val(t_ret));
}

void	__trace_segment(t_data *data, t_lstmap *A, t_lstmap *B)
{
	int	step;
	const float	dRGB[3] = {
		B->color->R - A->color->R,
		B->color->G - A->color->G,
		B->color->B - A->color->B,
	};
	// float	dxy[2] = {
	// 	(float) (B->point3D->x - A->point3D->x),
	// 	(float) (B->point3D->y - A->point3D->y),
	// };
	float	xy[2];
	// float	x;
	// float	y;
	int	i;
	float	dxy[2];
	
	dxy[0] = (float) (B->point3D->x - A->point3D->x);
	dxy[1] = (float) (B->point3D->y - A->point3D->y);
	if (fabs(dxy[0]) > fabs(dxy[1]))
		step = fabs(dxy[0]);
	else
		step = fabs(dxy[1]);
	if (step == 0)
		return ;
	dxy[0] = dxy[0] / step;
	dxy[1] = dxy[1] / step;
	i = 0;
	xy[0] = A->point3D->x;
	xy[1] = A->point3D->y;
	// printf("Range = %d\n", end - begin);
	while (i < step)
	{
		__img_pix_put(&(data->img), xy[1], xy[0], __degrade_color(A->color, dRGB, i, step));
		xy[0] += dxy[0];
		xy[1] += dxy[1];
		i++;
	}
}