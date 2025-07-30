/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:54:11 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 19:41:59 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_utils.h"
#include <unistd.h>

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

int	map_exec(char *path)
{
	t_map	map;
	char	*str_map;

	str_map = ft_map_to_str(path);
	if (str_map == NULL)
		return (1);
	if (ft_parse_map(&map, str_map) == NULL)
		return (2);
	free(str_map);
	if (map_convert_to_int(&map))
		return (3);
	if (map_checking(&map))
		return (4);
	map_modifying(&map);
	ft_putstr_array(map.map, "\n");
	free_tmap(&map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	exec_res;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			exec_res = map_exec(argv[i]);
			if (exec_res == 1)
				ft_putstr("Error (File reading)\n");
			else if (exec_res == 2)
				ft_putstr("map error\n");
			else if (exec_res == 3)
				ft_putstr("Error (Int map initialisation)\n");
			else if (exec_res == 4)
				ft_putstr("Error (Checking)\n");
			ft_putstr("\n");
			i++;
		}
	}
	else if (argc == 1)
		map_exec(NULL);
	return (0);
}
