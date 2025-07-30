/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling_with_bsq.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:54:07 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 12:41:18 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_map.h"

void	map_modifying(t_map *map)
{
	int	i;
	int	j;

	i = map->biggest_row_index;
	j = map->biggest_col_index;
	while (i > (int) map->biggest_row_index - (int) map->biggest_value || i > 0)
	{
		while (j > (int)map->biggest_col_index - (int)map->biggest_value
			|| j > 0)
		{

			map->map[i][j] = map->full_char;
			j--;
		}
		j = map->biggest_col_index;
		i--;
	}
}
