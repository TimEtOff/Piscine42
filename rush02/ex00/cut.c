/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:50:07 by mboutte           #+#    #+#             */
/*   Updated: 2025/07/27 23:14:28 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_file(char *path);

void	ft_write_file(char *path);

char	*ft_find(char *nb, char *path);

char	*ft_select(char *str);

int		ft_len_file(char *path);

int		ft_strlen(char *str);

char	*ft_strjoin(int size, char **strs, char *sep);

char	*ft_strdup(char *src);

char	*cut_z(char	*str);

char	*join_2(char *str1, char *str2);

char	*ft_mod(char *str, char *path);

char	*cut_z(char	*str);

char	*ft_rev(char *str, int size)
{
	char	c;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		c = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = c;
		i++;
	}
	return (str);
}

char	*ft_pow(int len, char *path)
{	
	char	*str;
	char	*res;
	int	i;
	
	str = malloc(sizeof(char) * len);
	str[0] = '1';
	i = 1;
	while (i < len)
		str[i++] = '0';
	str[i] = '\0';
	res = ft_find(str, path);
	free(str);
	return (res);
}


char	*get_didgit(char *str)
{
	char	*res;
	int		len;
	int		end;
	int		i;
	
	len = ft_strlen(str);
	end = ((len - 1) % 3) + 1;
	res = malloc(sizeof(char) * end + 1);
	i = 0;
	while (i < end)
	{
		res[i] = str[len - i - 1];
		i++;
	}
	res[i] = '\0';
	res = cut_z(res);
	return (res);
}

char	*get_last(char *str)
{
	char	*res;
	int		len;
	int		end;
	int		i;

	len = ft_strlen(str);
	end = (len - ((len - 1) % 3 + 1));
	res = malloc(sizeof(char) * (end + 1));
	i = 0;
	while (i < end)
	{
		res[i] = str[len - i - 1 - ((len - 1) % 3 + 1)];
		i++;
	}
	res[i] = '\0';
	res = cut_z(res);
	free(str);
	return (res);	
}

char	*cut(char *words, char *str, int j, char *path)
{
	char	*last;
	int	i;
	
	i = 0;
	if (ft_find(str, path) != NULL)
		return (join_2(words, ft_find(str, path)));
	if (ft_strlen(str) <= 3)
		return (join_2(words, ft_mod(str, path)));
	last = malloc(sizeof(char) * ft_strlen(str));
	while (i < ft_strlen(str))
	{
		last[i] = str[ft_strlen(str) - i - 1];
		str[ft_strlen(str) - 1 - i++] = '0';
		if (ft_find(str, path) != NULL)
		{
			last[i] = '\0';
			return (cut(join_2((join_2(words, ft_find(str, path))), ft_find(str, path)), ft_rev(last, i), j, path));
		}
	}
	last[i] = '\0';
	last = get_last(last);
	words = (join_2((join_2(words, ft_mod(get_didgit(last), path))), ft_pow(ft_strlen(str), path)));
	if (last == NULL)
		return (words);
	return cut(words, last, j, path);
}