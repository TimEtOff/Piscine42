/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:28:11 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/30 13:57:00 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdlib.h>

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
