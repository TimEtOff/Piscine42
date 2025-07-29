/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:36:39 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/28 13:10:21 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_arraylen(char **array)
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
		end = ft_str_arraylen(str);
	new_array = malloc(sizeof(char *) * (end - start));
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
