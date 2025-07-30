/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_reading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:15:13 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 19:54:29 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_utils.h"

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

void	read_user_input(void)
{
	char	buf[1024];
	int		i;
	char	**input;
	int		i_input;
	t_map	res;

	res.nb_row = 0;
	while (buf > 0 && (i_input != 0 || i_input < res.nb_row))
	{
		read(0, buf, sizeof(buf));
		i = 99;
		while (buf[i] != '\n')
			i--;
		buf[i] = '\0';
		i = 0;
		input[i_input] = ft_strdup(buf);
		if (i_input == 0)
			first_line(&res, input[0]);
		while (i < 1024)
		{
			buf[i] = '\0';
			i++;
		}
		i = 0;
	}
}

char	*ft_map_to_str(const char *filename)
{
	int		fd;
	int		file_len;
	char	*dict_to_str;

	if (filename == NULL)
		fd = 0;
	else
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
	dict_to_str[file_len - 1] = '\0';
	return (dict_to_str);
}
