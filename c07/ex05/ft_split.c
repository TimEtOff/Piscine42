/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:28:11 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/30 13:54:15 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_in(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*truncate_str(char *src, int start, int end)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (i < end - start)
	{
		res[i] = src[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
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

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		start;
	int		i_str;
	int		i;

	i = 0;
	start = 0;
	i_str = 0;
	res = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (str[i])
	{
		while (str[i] && is_in(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_in(str[i], charset))
			i++;
		if (start < i)
			res[i_str++] = truncate_str(str, start, i);
	}
	res[i_str] = 0;
	return (res);
}

/*int	main(int argc, char **argv)
{
	char	**res;
	int		i;

	if (argc >= 3)
	{
		i = 0;
		res = ft_split(argv[1], argv[2]);
		__builtin_printf("{");
		while (i < count_words(argv[1], argv[2]))
		{
			__builtin_printf("%s, ", res[i]);
			free(res[i]);
			i++;
		}
		__builtin_printf("%s}", res[i]);
		free(res);
	}
	return (0);
}*/
