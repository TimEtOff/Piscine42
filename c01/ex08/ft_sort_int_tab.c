/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:15:28 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/11 14:11:47 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_min_i_int_tab(int *tab, int start, int size)
{
	int	i;
	int	min_i;
	int	min_val;

	i = start + 1;
	min_i = start;
	min_val = tab[min_i];
	while (i < size)
	{
		if (tab[i] < min_val)
		{
			min_i = i;
			min_val = tab[min_i];
		}
		i++;
	}
	return (min_i);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	min;

	i = 0;
	while (i < size)
	{
		min = ft_min_i_int_tab(tab, i, size);
		temp = tab[min];
		tab[min] = tab[i];
		tab[i] = temp;
		i++;
	}
}

/*void	print_tab(int *tab, int size)
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
	int	tab[6] = {4, 6, 8, 7, 1, 2};
	int	tab2[7] = {9, 4, 2, 3, 6, 8, 7};

	print_tab(tab, 6);
	ft_sort_int_tab(tab, 6);
	print_tab(tab, 6);
	print_tab(tab2, 7);
	ft_sort_int_tab(tab2, 7);
	print_tab(tab2, 7);
}*/
