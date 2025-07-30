/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:54:11 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 11:11:17 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "utils/ft_utils.h"
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

void	DBG_print_values_map(t_map *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			ft_putnbr(res->values_map[i][j]);
			ft_putstr("	");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}

int	map_exec(char *path)
{
	t_map	map;
	char	*str_map;

	str_map = ft_map_to_str(path);
	if (str_map == NULL)
		return (1);
	if (ft_parse_map(&map, str_map) == NULL) // FIXME A lot of valgrind errors because of ft_split and others
		return (2);
	free(str_map);
	if (map_convert_to_int(&map))
		return (3);
	if (map_checking(&map))
		return (4);
	DBG_print_values_map(&map);
	free_tmap(&map);
	return (0);
}
/*
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
				ft_putstr("Error (Parsing)\n");
			else if (exec_res == 3)
				ft_putstr("Error (Int map initialisation)\n");
			else if (exec_res == 4)
				ft_putstr("Error (Checking)\n");
			i++;
		}
	}
	
	return (0);
}
*/
