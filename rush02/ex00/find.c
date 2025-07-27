/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:54:43 by mboutte           #+#    #+#             */
/*   Updated: 2025/07/26 16:49:18 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_len_file(char *path)
{
	void	*buf;
	int		fd;
	int		add;
	int		res;

	fd = open(path, O_RDONLY);
	buf = malloc(sizeof(char) * 128);
	add = read(fd, buf, sizeof(buf));
	res = 0;
	while (add > 0)
	{
		res += add;
		add = read(fd, buf, sizeof(buf));
	}
	free(buf);
	return (res);
}

char	*get_file(char *path)
{
	void	*file;
	char	*str;
	int		fd;
	int		size;

	size = ft_len_file(path);
	file = malloc(size + 1);
	fd = open(path, O_RDONLY);
	read(fd, file, size);
	close(fd);
	str = (char *)file;
	str[size + 1] = '\0';
	return (str);
}

void	ft_write_file(char *path)
{
	void	*file;
	int		size;
	int		fd;	

	size = ft_len_file(path);
	file = malloc(size);
	fd = open(path, O_RDONLY);
	read(fd, file, size);
	write(1, file, size);
	close(fd);
}

char	*ft_select(char *str)
{
	char	*word;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (str[start] == ' ')
		start++;
	start++;
	while (str[start] == ' ')
		start++;
	end = start;
	while (str[end] && str[end] != '\n')
		end++;
	word = malloc(sizeof(char) * (end - start));
	i = 0;
	while (start + i < end)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*ft_find(char *nb, char *path)
{
	char	*file;
	int		i;
	int		j;
	int		motif_found;

	file = get_file(path);
	i = 0;
	motif_found = 0;
	while (file[i] && motif_found == 0)
	{
		j = 0;
		while (file[i + j] == nb[j] && file[i + j] && nb[j])
			j++;
		if (nb[j] == '\0' && (file[i + j] == ' ' || file[i + j] == ':'))
		{
			motif_found = 1;
			i += j - 1;
		}
		i++;
	}
	if (motif_found == 0)
		return ("");
	return (ft_select(&file[i]));
}

/*int	main(void)
{
	char	path[] = "numbers.dict";
	int	size_file;

	size_file = ft_len_file(path);
	if (size_file == 0)
		write(1, "Dict Error\n", 11);
	else
		(void)0;		
		//ft_write_file(path);
	__builtin_printf("15=%s\n", ft_find("15", path));
	__builtin_printf("50=%s\n", ft_find("50", path));
	__builtin_printf("90=%s\n", ft_find("90", path));
	__builtin_printf("1000000=%s\n", ft_find("1000000", path));
}*/
