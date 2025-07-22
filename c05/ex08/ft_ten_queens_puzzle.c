/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:54:37 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/22 15:52:27 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *solution)
{
	int	res;
	int	ind;
	int	diff;

	res = 1;
	ind = 0;
	while (ind < 9)
	{
		diff = (solution[ind] - '0') - (solution[ind + 1] - '0');
		if (diff < 0)
			diff = -diff;
		if (diff < 2)
			res = 0;
		ind++;
	}
	return (res);
}

int	ft_ten_queens_puzzle(void)
{
	int		count;

	count = 0;
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", is_valid("0257948163"));
	return (0);
}*/
