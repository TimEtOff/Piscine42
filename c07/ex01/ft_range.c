/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:16:27 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/23 14:01:09 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	size;

	if (min > max)
		return (0);
	size = max - min;
	range = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

/*#include <stdio.h>

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	printf("%c", '{');
	while (i < size - 1)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	printf("%d}\n", tab[i]);
}

int	main(void)
{
	print_tab(ft_range(5, 10), 5);
	print_tab(ft_range(0, 451), 451);
	return (0);
}*/
