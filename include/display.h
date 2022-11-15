/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:41:00 by pgros             #+#    #+#             */
/*   Updated: 2022/11/15 18:49:41 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "mlx.h"
# include "map.h"


# define MLX_ERROR			1
# define MLX_INIT_SUCCESS	0

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	// t_img	img;
	// t_map	*map;
}	t_data;

int		handle_no_event(t_data *data);
int		handle_leave(t_data *data);

void	__mlx_display(t_data *data);
int		__initialize(t_data *data);


#endif