/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:10:51 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 13:28:12 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

/*
	We need to use two distinct values:
		- X
		- Y
	which will be used as indexes
	In order to make this works, we need to make two loops, where we print-out Xs and Ys lines.
	Example of an X line:
		o---o
	Example of an Y line:
		|   |
	For every iterations, we need to track for:
		- An odd number of Ys, such that:
			- an odd number of Ys that is superior to 1 would generate a print of one first X and one last X.
			- Y is always subtracted by two.
	*/
void	rush(int x, int y)
{
	int	incr_x;
	int	incr_y;

	incr_x = 0;
	incr_y = 0;
	while (incr_y < y)
	{
		while (incr_x < x)
		{
			if (incr_y == 0) // Si c'est la première ligne
			{
				if (incr_x == 0 || incr_x == (x - 1)) // Si c'est un coin
					write(1, "o", 1);
				else
					write(1, "-", 1);
			}
			else
			{
				write(1, "X", 1);
			}
			incr_x++;
		}
		write(1, "\n", 1);
		incr_y++;
	}

}
