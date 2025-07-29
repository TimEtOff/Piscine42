/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:37:43 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/29 16:27:22 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_utils.h"
#include "ft_map.h"

int	map_values_mallocing(t_map *map)
{
	unsigned int	i;

	i = 0;
	map->values_map = malloc(sizeof(unsigned int *) * map->nb_row + 1);
	if (!map->values_map)
		return (1);
	while (i < map->nb_col)
	{
		map->values_map[i] = malloc(sizeof(unsigned int) * map->nb_col + 1);
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

int	map_checking(t_map *map)
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
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}
