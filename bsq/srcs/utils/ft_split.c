/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:28:11 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/27 17:51:39 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_in(char c, char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res = 1;
		i++;
	}
	return (res);
}

int	strlen_set(char	*str, char	*charset)
{
	int	i;

	i = 0;
	while (!is_in(str[i], charset) && str[i] != '\0')
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 && !is_in(str[i], charset))
			|| (!is_in(str[i], charset)
				&& is_in(str[i - 1], charset)))
			res++;
		i++;
	}
	return (res);
}

void	split_loop(char **res, char *str, char *charset, int *i_str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (is_in(*str, charset))
		{
			res[*i_str][i] = '\0';
			(*i_str)++;
			i = 0;
			while (is_in(*str, charset))
				str++;
			res[*i_str] = malloc(sizeof(char) * strlen_set(str, charset) + 1);
			res[*i_str][0] = '\0';
		}
		else
		{
			res[*i_str][i] = *str;
			str++;
			i++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i_str;

	res = malloc(sizeof(char *) * count_words(str, charset) + 1);
	if (res == NULL)
		return (0);
	i_str = 0;
	if (count_words(str, charset))
	{
		while (is_in(*str, charset))
			str++;
		res[i_str] = malloc(sizeof(char) * strlen_set(str, charset) + 1);
		res[i_str][0] = '\0';
		split_loop(res, str, charset, &i_str);
	}
	return (res);
}
