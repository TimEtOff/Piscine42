/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:35:49 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/30 19:31:39 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_utils.h"

int	is_valid_char(char c, t_map *map)
{
	int	res;

	res = 0;
	if (c == map->empty_char || c == map->obstacle_char)
		res = 1;
	return (res);
}

int	map_chars_are_unique(t_map *map)
{
	int	res;

	res = 1;
	if (map->empty_char == map->obstacle_char
		|| map->empty_char == map->full_char
		|| map->obstacle_char == map->full_char)
		res = 0;
	return (res);
}

int	first_line(t_map *res, char *line)
{
	int		size;
	int		i;
	char	*truncated;

	size = ft_strlen(line);
	i = size - 1;
	if (size < 4 || !ft_str_is_printable(line))
		return (1);
	res->full_char = line[i];
	i--;
	res->obstacle_char = line[i];
	i--;
	res->empty_char = line[i];
	if (!map_chars_are_unique(res))
		return (1);
	truncated = truncate_str(line, 0, i);
	i = ft_atoi(truncated);
	free(truncated);
	if (i <= 0)
		return (1);
	res->nb_row = i;
	return (0);
}

int	map_is_valid(char **full_map, t_map *res)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 0;
	if ((unsigned int) ft_arraylen((void *) full_map) - 1 != res->nb_row)
		return (0);
	while (i < res->nb_row)
	{
		if ((unsigned int) ft_strlen(full_map[i]) != res->nb_col)
			return (0);
		while (j < res->nb_col)
		{
			if (!is_valid_char(full_map[i][j], res))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_map	*ft_parse_map(t_map *res, char *str_map)
{
	char			**full_map;

	full_map = ft_split(str_map, "\n");
	if (ft_arraylen((void *) full_map) < 2)
		return (NULL);
	if (first_line(res, full_map[0]))
		return (NULL);
	res->nb_col = ft_strlen(full_map[1]);
	if (!map_is_valid(full_map, res))
		return (NULL);
	res->map = truncate_str_array(full_map, 1, ft_arraylen((void *) full_map));
	free(full_map[0]);
	free(full_map);
	return (res);
}
