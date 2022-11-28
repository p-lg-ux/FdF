/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filepath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:52:00 by pgros             #+#    #+#             */
/*   Updated: 2022/11/28 19:54:17 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__check_filepath(char *filepath)
{
	int	len;

	len = ft_strlen(filepath);
	if (len <= 4)
		return (1);
	if (ft_strncmp(".fdf", filepath + (len - 4), 5) != 0)
		return (1);
	return (0);
}
