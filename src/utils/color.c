/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:20:27 by pgros             #+#    #+#             */
/*   Updated: 2022/11/11 18:29:48 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "color.h"

t_color	*to_t_color(int	val)
{
	t_color	*ret;

	ret = malloc(sizeof(t_color));
	if (ret == NULL)
		return (NULL);
	ret->val = val;
	ret->R = (val & RED) >> 16;
	ret->G = (val & GREEN) >> 8;
	ret->B = (val & BLUE);	
	return (ret);
}

int	to_val(t_color color)
{
	int	val;
	
	val = (color.R << 16) + (color.G << 8) + color.B;
	return (val);
}
