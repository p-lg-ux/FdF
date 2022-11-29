/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:41:00 by pgros             #+#    #+#             */
/*   Updated: 2022/11/29 15:21:43 by pgros            ###   ########.fr       */
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
	int		bpp;
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

typedef void	(*t_ft_key_handle)(t_data *data);

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
void	__set_map_transform(t_map *map);
void	__center_scale(t_data *data);

void	__trace_segment(t_data *data, t_lstmap *A, t_lstmap *B);
int		__degrade_color(t_color *begin, const float dRGB[3], int i, int step);

void	__handle_rotz_pos(t_data *data);
void	__handle_rotz_neg(t_data *data);
void	__handle_roty_pos(t_data *data);
void	__handle_roty_neg(t_data *data);
void	__handle_rotx_pos(t_data *data);
void	__handle_rotx_neg(t_data *data);
void	__handle_zoom_pos(t_data *data);
void	__handle_zoom_neg(t_data *data);
void	__handle_tx_up(t_data *data);
void	__handle_tx_down(t_data *data);
void	__handle_ty_left(t_data *data);
void	__handle_ty_right(t_data *data);

#endif