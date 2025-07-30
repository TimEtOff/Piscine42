/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:36:39 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/30 17:37:14 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdlib.h>

int	ft_arraylen(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**truncate_str_array(char **str, int start, int end)
{
	char	**new_array;
	int		i;

	if (end == -1)
		end = ft_arraylen((void *) str);
	new_array = malloc(sizeof(char *) * (end - start + 1));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		new_array[i] = str[start + i];
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

void	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_putstr_array(char **array, char *sep)
{
	int	i;

	i = 0;
	while (i < ft_arraylen((void *) array))
	{
		ft_putstr(array[i]);
		ft_putstr(sep);
		i++;
	}
}
