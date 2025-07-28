/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:37:43 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 13:27:42 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_map.h"

void	map_convert_to_int(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((unsigned long) i < (*map).nb_row)
	{
		while ((unsigned long) j < (*map).nb_col)
		{
			if ((*map).map[i][j] == (*map).empty_char)
				(*map).values_map [i][j] = 1;
			else
				(*map).values_map [i][j] = 0;
			j++;
		}
		i++;
	}
}

void	map_cheching(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < (*map).nb_row)
	{
		while (col < (*map).nb_col)
		{
			if (row == 0 || col == 0)
				(*map).values_map [row][col] = (*map).map[row][col];
			else if ((*map).map[row][col] > 0)
			{
				(*map).values_map [row][col] = 1 + ft_min (
						(*map).map[row - 1][col],
						(*map).map[row][col - 1],
						(*map).map[row - 1][col - 1]);
			}
		}
	}
}
