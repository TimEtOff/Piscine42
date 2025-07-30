/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling_with_bsq.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yriffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:54:07 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 11:26:52 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_utils.h"
#include "ft_map.h"

void	map_modifying(t_map *map)

{
	int	i;

	i = map->biggest_value;
	row = map->biggest_row_index;
	col = map->biggest_col_index;
	while(i > 0)
	{
		map->map[row][col] = map->full_char;
		row--;
		col--;
		i--;	
	}
	__builtin_printf("%s",map->map);
}
/*
int	main(int ac, char **argv)

{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			__builtin_printf("%s",map->map[i][j])
			ft_putstr("	");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
}\*/
