/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yriffard <yriffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:04:45 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/30 20:11:38 by yriffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"

int	get_size(int size, char **strs, char *sep)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		res += ft_strlen(strs[i]);
		i++;
	}
	res += ft_strlen(sep) * (size - 1);
	if (size <= 0)
		res = 1;
	res++;
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		size_m;

	size_m = get_size(size, strs, sep);
	res = malloc(sizeof(char) * size_m);
	if (res == NULL)
		return (0);
	res[0] = '\0';
	i = 0;
	if (size > 0)
	{
		while (i < size)
		{
			str_append(res, strs[i]);
			if (i < size - 1)
				str_append(res, sep);
			i++;
		}
		res[size_m - 1] = '\0';
	}
	return (res);
}
