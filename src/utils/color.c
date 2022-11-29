/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:20:27 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 15:52:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "color.h"

t_color	*to_t_color(int val)
{
	t_color	*ret;

	ret = malloc(sizeof(t_color));
	if (ret == NULL)
		return (NULL);
	ret->val = val;
	ret->r = (val & RED) >> 16;
	ret->g = (val & GREEN) >> 8;
	ret->b = (val & BLUE);
	return (ret);
}

int	to_val(t_color color)
{
	int	val;

	val = (color.r << 16) + (color.g << 8) + color.b;
	return (val);
}
