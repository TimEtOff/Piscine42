/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:37:43 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 20:57:08 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_utils.h"
#include "ft_map.h"
#include <stdio.h>

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
	int	row;
	int	col;

	row = 0;
	col = 0;
	if (map_values_mallocing(map))
		return (1);
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
		row++;
	}
	return (0);
}

/*int	main(void) // TODO Penser à supp

{
	__builtin_printf("%s","debut");
	t_map map ;
	int	i;
	int	j;
	 __builtin_printf("%s","debut");
	char *map_[4] = { "....","....","....","...o"};
	map.nb_row = 4;
	map.nb_col = 4;
	map.empty_char = '.';
	map.obstacle_char = 'o';
	map.full_char = 'x';
	map.nb_row = 4;
	map.map =map_;
	
	i = 0;
	j = 0;
	map_convert_to_int(&map);
	__builtin_printf("%s","apres convert");
	map_checking(&map);
	__builtin_printf("%s","apres ccheck");
	while (i < 4)
	{
		while (j < 4)
		{
			__builtin_printf("%d",map.values_map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}*/
