/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:54:11 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 15:04:36 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_utils.h"

char	*ft_map_to_str(const char *filename);
t_map	*ft_parse_map(t_map *res, char *str_map);
void	map_convert_to_int(t_map *map);
void	map_cheching(t_map *map);

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	if (argc >= 2)
	{
		ft_parse_map(&map, ft_map_to_str(argv[1]));
		map_convert_to_int(&map);
		map_cheching(&map);
		i = 0;
		while (i < ft_str_arraylen(map.map))
		{
			__builtin_printf("%d\n",*map.values_map[i]);
			i++;
		}
	}

	return (0);
}
