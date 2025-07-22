/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:42:49 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/22 17:57:58 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_min_i_char_tab(char **tab, int start, int size)
{
	int	i;
	int	min_i;
	int	min_val;

	i = start + 1;
	min_i = start;
	min_val = tab[min_i][0];
	while (i < size)
	{
		if (tab[i][0] < min_val)
		{
			min_i = i;
			min_val = tab[min_i][0];
		}
		i++;
	}
	return (min_i);
}

void	ft_sort_char_tab(char **tab, int size)
{
	int		i;
	char	*temp;
	int		min;

	i = 1;
	while (i < size)
	{
		min = ft_min_i_char_tab(tab, i, size);
		temp = tab[min];
		tab[min] = tab[i];
		tab[i] = temp;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_char_tab(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
