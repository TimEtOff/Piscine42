/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling_with_bsq.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:54:07 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 12:51:26 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_map.h"

void	map_modifying(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < map->biggest_value)
	{
		while (j < map->biggest_value)
		{
			map->map[map->biggest_row_index - i][map->biggest_col_index - j]
				= map->full_char;
			j++;
		}
		j = 0;
		i++;
	}
}
