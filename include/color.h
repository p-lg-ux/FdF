/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:21:00 by pgros             #+#    #+#             */
/*   Updated: 2022/11/11 18:41:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

typedef struct s_color
{
	int	val;
	int	R;
	int	G;
	int B;
}	t_color;

t_color	*to_t_color(int	val);
int		to_val(t_color color);

#endif