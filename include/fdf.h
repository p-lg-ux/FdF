/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:05:29 by pgros             #+#    #+#             */
/*   Updated: 2022/11/04 17:17:03 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"lib42.h"
#include	"mlx.h"
#include 	"geometry.h"
#include 	"map.h"

typedef char**		t_strtab;


t_map	*parse(char *filepath);

//UTILS

// t_str_tab
void	__free_strtab(t_strtab tab);
int		__strtab_len(t_strtab tab);

//t_map
void	__print_map(t_map *map);
void	__free_maptab(t_maptab maptab);
void	__free_map(t_map *map);

#endif