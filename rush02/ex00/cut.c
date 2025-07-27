/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:50:07 by mboutte           #+#    #+#             */
/*   Updated: 2025/07/27 16:48:38 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define d_path "numbers.dict"

char	*get_file(char *path);

void	ft_write_file(char *path);

char	*ft_find(char *nb, char *path);

char	*ft_select(char *str);

int	ft_len_file(char *path);

int	ft_strlen(char *str);

char	*ft_strjoin(int size, char **strs, char *sep);

char	*ft_strdup(char *src);

char	*cut_z(char	*str);

char *ft_rm_first_n(char *str, int char_rm)
{
	char *res;
	int	i;

	i = 1;
	res = malloc(sizeof(char) * (char_rm + 2));
	while (i < char_rm)
	{
		res[i] = str[char_rm - i];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

char	*ft_mod(char *str)
{
	int	i;
	char lettre[3];
	char	**words;

	__builtin_printf("\nft_mod input : str =%s", str);	
	words = malloc(sizeof(char *) * 15);
	if (ft_find(str, d_path) != NULL)
	{
		return (ft_find(str, d_path));
	}

	lettre[1] = '\0';
	i = 0;
	if (ft_strlen(str) == 3)
	{
		lettre[0] = str[0];
		words[i++] = ft_find(lettre, d_path);
		words[i++] = ft_find("100", d_path);
		str = ft_strdup(&str[1]);
		str = cut_z(str);
		if (str == NULL)
			return (ft_strjoin(i, words, " "));
	}
	if (ft_strlen(str) == 2)
	{
		if (ft_find(str, d_path) != NULL)
		{
			words[i++] = ft_find(str, d_path);
			return (ft_strjoin(i, words, " "));
		}
		lettre[0] = str[0];
		lettre[1] = '0';
		lettre[2] = '\0';
		words[i++] = ft_find(lettre, d_path);
		str = ft_strdup(&str[1]);
	}
	words[i++] = ft_find(str, d_path);
	return ft_strjoin(i, words, " ");
}

char	*ft_rev(char *str, int size)
{
	int	i = 0;
	char	c;
	while (i < size / 2)
	{
		c = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = c;
		i++;
	}
	return (str);
}

char	*ft_pow(int len)
{	
	char	*str;
	char	*res;
	int	i;
	
	len = len - ((len - 1) % 3);
	str = malloc(sizeof(char) * len);
	str[0] = '1';
	i = 1;
	while (i < len)
		str[i++] = '0';
	str[i] = '\0';
	res = ft_find(str, d_path);
	free(str);
	return (res);
}

char	*cut_z(char	*str)
{
	char	*res;
	int		nb_z;
	int		i;

	i = 0;
	nb_z = 0;
	while (str[i] && str[i] == '0')
	{
		nb_z++;
		i++;
	}
	if (nb_z == 0)
		return (str);
	if (nb_z == ft_strlen(str))
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(str) - nb_z + 1));
	i = 0;
	while(i + nb_z < ft_strlen(str))
	{
		res[i] = str[nb_z + i];
		i++;
	}
	res[i] = '\0';
	//free(str);
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
	__builtin_printf("\noutput didgit|str=%s|output=%s", str, res);
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
	__builtin_printf("\noutput last|str=%s|output=%s", str, res);
	free(str);
	return (res);	
}

char	**cut(char **words, char *str, int index)
{
	char	*res;
	int		len;
	char	*last;
	int	i;
	char	*didgit;
	
	len = ft_strlen(str);
	__builtin_printf("\n-----------------\nstart cut : index = %d| str =%s| len = %d", index, str, len);
	i = 0;
	malloc(sizeof(char) * 10);
	res = ft_find(str, d_path);
	if (res != NULL)
	{
		words[index] = res;
		return (words);
	}
	if (len <= 3)
	{
		words[index] = ft_mod(str);
		return (words);
	}
	last = malloc(sizeof(char) * ft_strlen(str));
	while (i < ft_strlen(str))
	{
		last[i] = str[len - i - 1];
		str[len - 1 - i] = '0';
		if (ft_find(str, d_path) != NULL)
		{
			words[index++] = ft_find(str, d_path);
			last[i + 1] = '\0';
			return (cut(words, ft_rm_first_n(last, i), index));
		}
		i++;
	}
	last[i] = '\0';
	__builtin_printf("\nlast befoor cutting ==%s", last);
	didgit = get_didgit(last);
	last = get_last(last);
	__builtin_printf("\nafter cutting didgit =%s, last =%s", didgit, last);
	words[index++] = ft_mod(didgit);
	words[index++] = ft_pow(len);
	int	y = -1;
	__builtin_printf("\n");
	while (++y < index)
		__builtin_printf("words[%d]=%s||", y,  words[y]);
	__builtin_printf("just bef recu last = %s|", str);
	if (last == NULL)
		return (words);
	return cut(words, last, index);
}

int	main(int ac, char **av)
{
	char	**words;

	(void)ac;
	words = malloc(sizeof(char *) * 100);
	if (ac > 1)
		words = cut(words, av[1], 0);
	else
		__builtin_printf("plz put arg in a.out");
	__builtin_printf("\n--------------------------");
	__builtin_printf("\n%s", words[0]);
	__builtin_printf("\n%s", words[1]);
	__builtin_printf("\n%s", words[2]);
	__builtin_printf("\n%s", words[3]);
	__builtin_printf("\n%s", words[4]);
	__builtin_printf("\n%s", words[5]);
	return (0);
}
