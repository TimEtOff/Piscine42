/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:35:49 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/28 13:14:26 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "utils/ft_utils.h"

int	first_line(t_map *res, char *line)
{
	int		size;
	int		i;
	char	*truncated;

	size = ft_strlen(line);
	i = size - 1;
	if (size < 4)
		return (1);
	(*res).full_char = line[i];
	i--;
	(*res).obstacle_char = line[i];
	i--;
	(*res).empty_char = line[i];
	i--;
	truncated = truncate_str(line, 0, i);
	(*res).nb_row = ft_atoi(truncated);
	free(truncated);
	return (0);
}

t_map	*ft_parse_map(t_map *res, char *str_map)
{
	char	**full_map;
	int		i;

	full_map = ft_split(str_map, "\n");
	if (ft_str_arraylen(full_map) < 2)
		return (res);
	if (first_line(res, full_map[0]))
		return (res);
	(*res).nb_row = ft_strlen(full_map[1]);
	i = 1;
	while (i < (int)(*res).nb_row)
	{
		if (ft_strlen(full_map[i]) != (int)(*res).nb_row)
			return (res);
		i++;
	}
	(*res).map = truncate_str_array(full_map, 1, ft_str_arraylen(full_map));
	free_array(full_map);
	return (res);
}
