/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_reading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:15:13 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/29 16:07:35 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils/ft_utils.h"

int	ft_file_size(int fd)
{
	int		count;
	int		readvalue;
	char	temp_c;

	count = 0;
	readvalue = 1;
	while (readvalue > 0)
	{
		readvalue = read(fd, &temp_c, 1);
		count++;
	}
	return (count);
}

char	*ft_map_to_str(const char *filename)
{
	int		fd;
	int		file_len;
	char	*dict_to_str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file_len = ft_file_size(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	dict_to_str = malloc(sizeof(char) * (file_len + 1));
	if (dict_to_str == NULL)
		return (NULL);
	*dict_to_str = '\0';
	read(fd, dict_to_str, file_len);
	close(fd);
	dict_to_str[file_len] = '\0';
	return (dict_to_str);
}
