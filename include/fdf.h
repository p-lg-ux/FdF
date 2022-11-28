/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/28 18:58:59 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	"lib42.h"
# include 	"geometry.h"
# include 	"map.h"
# include	"color.h"
# include	"display.h"

// # define COLOR_MAX		0xfea542 //orange
// # define COLOR_MIN		0x55d3fa //blue
// # define MAX_R			0xfe
// # define MAX_G			0xa5
// # define MAX_B			0x42
// # define MIN_R			0x55
// # define MIN_G			0xd3
// # define MIN_B			0xfa
// # define D_R			169
// # define D_G			-46
// # define D_B			-184

# define EXTENSION_ERR_MESS	"File must have .fdf extension\n"

# define COLOR_MAX		0xff0000 //red
# define COLOR_MIN		0x0000ff //blue
# define D_COLOR        0xfeff01
# define MAX_R			0xff
# define MAX_G			0x00
# define MAX_B			0x00
# define MIN_R			0x00
# define MIN_G			0x00
# define MIN_B			0xff
# define D_R			255
# define D_G			0
# define D_B		    -255

//	parse_bis.c
void	__check_lowest(t_map **map, t_point_i3 *point3D);
void	__check_highest(t_map **map, t_point_i3 *point3D);
int		__nblen(char *line);
int		__is_nb_start(char *line, int i);

//	parse.c
int		__add_point_to_map(t_map **map, int x, int y, int z);
int		__count_columns(t_map **map, char *line);
void	__count_lines_columns(t_map **map, int fd);
void	__fill_map(t_map **map, int fd);
void	__init_map(t_map *map);
t_map	*__parse(char *filepath);

//	set_colors.c
int		__set_colors(t_map *map);
t_color	*__define_color(t_lstmap *node, t_map *map);
t_color	*__compute_color(t_lstmap *node, t_map *map);

//	check_filepath.c
int		__check_filepath(char *filepath);

//UTILS

//t_map
void	__print_map(t_map *map);
/*void	__free_maptab(t_maptab maptab);*/
void	__free_map(t_map *map);

#endif