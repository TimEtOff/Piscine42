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
#include "utils/ft_utils.h"

void	free_tmap(t_map *map)
{
	unsigned long	i;

	i = 0;
	while (i < map->nb_row)
	{
		free(map->map[i]);
		free(map->values_map[i]);
		i++;
	}
	free(map->map);
	free(map->values_map);
}

void	map_exec(char *path)
{
	t_map	map;
	int		i;
	char	*str_map;

	str_map = ft_map_to_str(path);
	ft_parse_map(&map, str_map);
	free(str_map);
	map_convert_to_int(&map);
	map_cheching(&map);
	i = 0;
	while (i < ft_str_arraylen(map.map))
	{
		__builtin_printf("%s\n", map.map[i]);
		i++;
	}
	free_tmap(&map);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc >= 2)
	{
		i = 2;
		while (i <= argc)
		{
			map_exec(argv[i]);
			i++;
		}
	}
	return (0);
}
