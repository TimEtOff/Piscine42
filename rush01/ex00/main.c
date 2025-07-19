/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:50:28 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/19 15:40:06 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 4

void	ft_putchar(char c);
void	init_grid(void);
void	free_grid(void);
void	draw_grid(void);
void	set_val(int i, int j, int val);
int		get_val(int i, int j);

int	get_size(void)
{
	return (SIZE);
}

int	put_in_grid(char *input, int index, int i, int j)
{
	int	max;

	max = index + 8;
	while (index < max)
	{
		if (('0' <= input[index]) && (input[index] <= '9'))
			set_val(i, j, input[index] - '0');
		if (!(j == 0 || j == SIZE + 1))
			j++;
		else
			i++;
		index++;
		if (input[index] == ' ')
			index++;
	}
	return (index);
}

int	init_input(char *input)
{
	int	res;
	int	index;

	res = 0;
	index = 0;
	index = put_in_grid(input, index, 0, 1);
	index = put_in_grid(input, index, SIZE + 1, 1);
	index = put_in_grid(input, index, 1, 0);
	index = put_in_grid(input, index, 1, SIZE + 1);
	return (res);
}

int	main(int argc, char **argv)
{
	int	res;

	res = 0;
	init_grid();
	if (argc == 2)
	{
		if (init_input(argv[1]))
			res = 1;
		else
			draw_grid();
	}
	else
		res = 1;
	free_grid();
	return (res);
}
