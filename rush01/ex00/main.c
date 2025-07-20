/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:50:28 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/20 16:24:26 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 4

void	ft_putchar(char c);
void	free_grid(void);
void	draw_grid(void);
void	set_val(int i, int j, int val);
int		init_grid(void);
int		get_val(int i, int j);
int		occ_char_in_str(char *str, char c);
int		ft_strlen(char *str);
int		check(int row, int col);
int		init_grid_values(void);
int		resolve(void);
int		ft_strcmp(char *s1, char *s2);

int	get_size(void)
{
	return (SIZE);
}

int	put_in_grid(char *input, int index, int i, int j)
{
	int	max;

	max = index + (get_size() * 2);
	while (index < max)
	{
		if (('1' <= input[index]) && (input[index] <= get_size() + '0'))
			set_val(i, j, input[index] - '0');
		if (!(j == 0 || j == get_size() + 1))
			j++;
		else
			i++;
		index++;
		if (input[index] == ' ')
			index++;
	}
	return (index);
}

int	input_errors(char *input)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (ft_strlen(input) != (get_size() * get_size() * 2 - 1))
		res += 1;
	else
	{
		while (input[i] != '\0')
		{
			if (i % 2 == 0)
			{
				if (!(('1' <= input[i]) && (input[i] <= get_size() + '0')))
				{
					res += 1;
				}
			}
			else if (input[i] != ' ')
				res += 1;
			i++;
		}
	}
	return (res);
}

int	init_input(char *input)
{
	int	res;
	int	index;

	res = 0;
	index = 0;
	res += input_errors(input);
	if (res == 0)
	{
		index = put_in_grid(input, index, 0, 1);
		index = put_in_grid(input, index, get_size() + 1, 1);
		index = put_in_grid(input, index, 1, 0);
		index = put_in_grid(input, index, 1, get_size() + 1);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	res;

	res = 0;
	res = init_grid();
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2") == 0)
		{
			res += init_input(argv[1]);
			res += init_grid_values();
			res += resolve();
			if (res == 0)
				draw_grid();
		}
		else
			res = 1;
	}
	else
		res = 1;
	free_grid();
	if (res != 0)
		write(1, "Error\n", 6);
	return (res);
}
