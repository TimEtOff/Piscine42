/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:37:43 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 14:44:29 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_utils.h"
#include "ft_map.h"

void	map_convert_to_int(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while ((unsigned long) row < map->nb_row)
	{
		while ((unsigned long) col < map->nb_col)
		{
			if (map->map[row][col] == map->empty_char)
				map->values_map [row][col] = 1;
			else
				map->values_map [row][col] = 0;
			col++;
		}
		row++;
	}
}

void	map_cheching(t_map *map)
{
	unsigned long int	row;
	unsigned long int	col;

	row = 0;
	col = 0;
	while (row < map->nb_row)
	{
		while (col < map->nb_col)
		{
			if (row == 0 || col == 0)
				map->values_map [row][col] = map->map[row][col];
			else if (map->map[row][col] > 0)
			{
				map->values_map [row][col] = 1 + ft_min (
						map->map[row - 1][col],
						map->map[row][col - 1],
						map->map[row - 1][col - 1]);
			}
		}
	}
}
