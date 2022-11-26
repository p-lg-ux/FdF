/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:41:00 by pgros             #+#    #+#             */
/*   Updated: 2022/11/26 17:19:51 by pgros            ###   ########.fr       */
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
# include "geometry.h"

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
	t_img	img;
	t_map	*map;
}	t_data;

void	__quit(t_data *data, int exit_code, char *message);

int		handle_no_event(t_data *data);
int		handle_leave(t_data *data);
int		handle_keypress(int keysym, t_data *data);

void	__mlx_display(t_data *data);
int		__initialize(t_data *data);
void	__set_hooks(t_data *data);
void	__reset_background(t_data *data);
void	__img_pix_put(t_img *img, int x, int y, int color);
void	__put_map_to_im(t_data *data);

void	__apply_transform_to_map(t_data *data, t_matrix *transform);
void	__apply_transform(t_data *data, t_matrix *transform);
// void	__isometric_projection(t_data *data);
void	__set_isometric_projection(t_map *map);
void	__center_scale(t_data *data);

void	__trace_segment(t_data *data, t_lstmap *A, t_lstmap *B);
int		__degrade_color(t_color *begin, const float dRGB[3], int i, int step);

#endif