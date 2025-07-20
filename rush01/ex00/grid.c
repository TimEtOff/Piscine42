/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:24:35 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/20 10:40:56 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		get_size(void);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

static int	**g_grid;

void	set_val(int i, int j, int val)
{
	g_grid[i][j] = val;
}

int	get_val(int i, int j)
{
	return (g_grid[i][j]);
}

int	init_grid(void)
{
	int	i;

	i = 0;
	g_grid = malloc(sizeof(int *[get_size() + 2]));
	if (g_grid == NULL)
		return (EXIT_FAILURE);
	while (i < get_size() + 2)
	{
		g_grid[i] = malloc(sizeof(int [get_size() + 2]));
		if (g_grid == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

void	free_grid(void)
{
	int	i;

	i = 0;
	while (i < get_size() + 2)
	{
		free(g_grid[i]);
		i++;
	}
	free(g_grid);
}

void	draw_grid(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= get_size() + 1)
	{
		while (j <= get_size() + 1)
		{
			ft_putnbr(get_val(i, j));
			if (j != get_size() + 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}
