/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:11:59 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/23 17:10:29 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min > max)
	{
		range = 0;
		return (0);
	}
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	__builtin_printf("%c", '{');
	while (i < size - 1)
	{
		__builtin_printf("%d, ", tab[i]);
		i++;
	}
	__builtin_printf("%d}\n", tab[i]);
}

int	main(void)
{
	int	**range;
	int	size;

	range = malloc(sizeof(int *));
	size = ft_ultimate_range(range, 5, 10);
	print_tab(*range, size);
	size = ft_ultimate_range (range, 0, 451);
	print_tab(*range, size);
	free(*range);
	free(range);
	return (0);
}
