/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:24:35 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/19 15:46:55 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		get_size(void);
void	ft_putchar(char c);

static int	**g_grid;

void	set_val(int i, int j, int val)
{
	g_grid[i][j] = val;
}

int	get_val(int i, int j)
{
	return (g_grid[i][j]);
}

void	init_grid(void)
{
	int	i;

	i = 0;
	g_grid = malloc(sizeof(int *[6]));
	while (i < 6)
	{
		g_grid[i] = malloc(sizeof(int [6]));
		i++;
	}
}

void	free_grid(void)
{
	int	i;

	i = 0;
	while (i < 6)
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

	i = 1;
	j = 1;
	while (i <= get_size())
	{
		while (j <= get_size())
		{
			ft_putchar(g_grid[i][j] + '0');
			if (j != get_size())
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}
