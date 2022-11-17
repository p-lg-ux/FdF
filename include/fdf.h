/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/17 15:09:18 by pgros            ###   ########.fr       */
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

# define COLOR_MAX		0xfea542 //orange
# define COLOR_MIN		0x55d3fa //blue
# define MAX_R			0xfe
# define MAX_G			0xa5
# define MAX_B			0x42
# define MIN_R			0x55
# define MIN_G			0xd3
# define MIN_B			0xfa
# define D_R			169
# define D_G			-46
# define D_B			-184

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
t_map	*__parse(char *filepath);

//	set_colors.c
int		__set_colors(t_map *map);
t_color	*__define_color(t_lstmap *node, t_map *map);
t_color	*__compute_color(t_lstmap *node, t_map *map);

//UTILS

// t_str_tab
// void	__free_strtab(t_strtab tab);
// int		__strtab_len(t_strtab tab);

//t_map
void	__print_map(t_map *map);
/*void	__free_maptab(t_maptab maptab);*/
void	__free_map(t_map *map);

#endif