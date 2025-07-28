/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:54:11 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 13:13:34 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_utils.h"

char	*ft_map_to_str(const char *filename);
t_map	*ft_parse_map(t_map *res, char *str_map);

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	if (argc >= 2)
	{
		ft_parse_map(&map, ft_map_to_str(argv[1]));
		i = 0;
		while (i < ft_str_arraylen(map.map))
		{
			__builtin_printf("%s\n", map.map[i]);
			i++;
		}
	}

	return (0);
}
