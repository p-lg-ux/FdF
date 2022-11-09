/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:16:11 by pgros             #+#    #+#             */
/*   Updated: 2022/11/09 18:15:28 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "geometry.h"

typedef struct s_lstmap
{
	t_pointf3		*point3D;
	struct s_lstmap	*next;
}	t_lstmap;

typedef struct s_map
{
	int			nb_lines;
	int			nb_columns;
	t_pointf3	*lowest;
	t_pointf3	*highest;
	t_lstmap	*lstmap;
	t_lstmap	*last;
}	t_map;

t_lstmap	*__lstmap_new(t_pointf3 *point3D);
int			__lstmap_size(t_lstmap *lst);
void		__lstmap_add_back(t_lstmap **lst, t_lstmap *new);
void		__lstmap_clear(t_lstmap **lst);
// t_lstmap	*__lstmap_map(t_lstmap *lst, void (*f)(void *));

void		__free_map(t_map *map);
void		__print_map(t_map *map);
void		__print_lstmap(t_lstmap *maptab);


#endif