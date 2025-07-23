/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:54:37 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/23 13:14:43 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int *solution, int col, int row)
{
	int	res;
	int	i;
	int	diff;

	res = 1;
	i = col - 1;
	diff = 1;
	while (i >= 0 && res == 1)
	{
		if (solution[i] == row)
			res = 2;
		if (row - diff >= 0 && solution[i] == row - diff)
			res = 3;
		else if (row + diff < 10 && solution[i] == row + diff)
			res = 4;
		i--;
		diff++;
	}
	return (res);
}

void	print_solution(int *solution)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = solution[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	find_solution(int *solution, int col, int *count)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < 10)
	{
		if (is_valid(solution, col, i) == 1)
		{
			res = 1;
			solution[col] = i;
			if (col < 9)
				res = find_solution(solution, col + 1, count);
			else
			{
				print_solution(solution);
				(*count)++;
			}
		}
		i++;
	}
	return (res);
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	int		solution[10];

	count = 0;
	find_solution(solution, 0, &count);
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_ten_queens_puzzle());
	return (0);
}*/
