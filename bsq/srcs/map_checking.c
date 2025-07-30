/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:37:43 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 18:47:44 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_map.h"

int	map_values_mallocing(t_map *map)
{
	unsigned int	i;

	i = 0;
	map->values_map = malloc(sizeof(unsigned int *) * (map->nb_row + 1));
	if (!map->values_map)
		return (1);
	while (i < map->nb_row)
	{
		map->values_map[i] = malloc(sizeof(unsigned int) * (map->nb_col + 1));
		if (!map->values_map[i])
			return (1);
		i++;
	}
	map->values_map[i] = 0;
	return (0);
}

int	map_convert_to_int(t_map *map)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	col = 0;
	if (map_values_mallocing(map))
		return (1);
	while (row < map->nb_row)
	{
		while (col < map->nb_col)
		{
			if (map->map[row][col] == map->empty_char)
				map->values_map [row][col] = 1;
			else
				map->values_map [row][col] = 0;
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

void	get_square_info(t_map *map, int row, int col)
{
	if (map->values_map [row][col] > map->biggest_value)
	{
		map->biggest_value = map->values_map [row][col];
		map->biggest_col_index = col;
		map->biggest_row_index = row;
	}
}

void	min_define(t_map *map, int col, int row)
{
	map->values_map [row][col] = 1 + ft_min (
			map->values_map[row - 1][col],
			map->values_map[row][col - 1],
			map->values_map[row - 1][col - 1]);
}

int	map_checking(t_map *map)
{
	unsigned long int	row;
	unsigned long int	col;

	row = 0;
	col = 0;
	map->biggest_value = 0;
	while (row < map->nb_row)
	{
		while (col < map->nb_col)
		{
			if (row == 0 || col == 0)
				map->values_map [row][col]
					= map->values_map[row][col];
			else if (map->values_map[row][col] > 0)
			{
				min_define(map, col, row);
			}
			get_square_info(map, row, col);
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}
