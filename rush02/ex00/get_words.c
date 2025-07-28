/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 22:54:01 by mboutte           #+#    #+#             */
/*   Updated: 2025/07/27 23:10:09 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*join_2(char *str1, char *str2);

char	*ft_find(char *nb, char *path);

char	*ft_strdup(char *src);

char	*cut_z(char	*str);

char	*ft_letter(char *str, int c)
{
	char	*letter;

	if (c == 0)
	{
		letter = malloc(sizeof(char) * 2);
		letter[0] = str[0];
		letter[1] = '\0';
	}
	else
	{
		letter = malloc(sizeof(char) * 3);
		letter[0] = str[0];
		letter[1] = '0';
		letter[2] = '\0';
	}
	return (letter);
}

char	*ft_mod(char *str, char *path)
{
	char	*letter;
	char	*words;

	words = (NULL);
	if (ft_find(str, path) != NULL)
		return (ft_find(str, path));
	if (ft_strlen(str) == 3)
	{
		letter = ft_letter(str, 0);
		words = join_2(words, ft_find(letter, path));
		words = join_2(words, ft_find("100", path));
		str = ft_strdup(&str[1]);
		str = cut_z(str);
		if (str == NULL)
			return (words);
	}
	if (ft_strlen(str) == 2)
	{
		if (ft_find(str, path) != NULL)
			return (join_2(words, ft_find(str, path)));
		words = join_2(words, ft_find(ft_letter(str, 1), path));
		str = ft_strdup(&str[1]);
	}
	words = join_2(words, ft_find(str, path));
	return (words);
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
	while (i + nb_z < ft_strlen(str))
	{
		res[i] = str[nb_z + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
