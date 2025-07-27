/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:54:11 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/27 15:29:18 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

/*
	Modified from `c02/ex03/ft_str_is_numeric.c`
*/
int	ft_char_is_numeric(char chr)
{
	int	res;

	res = 1;
	if (!(('0' <= chr) && (chr <= '9')))
		res = 0;
	return (res);
}

int	check_input(char *input)
{
	int	res;

	res = 0;
	if (ft_strlen(input) == 0)
		res = 1;
	while (*input)
	{
		if (!ft_char_is_numeric(*input))
			res = 1;
		input++;
	}
	return (res);
}

int	write_num(char *input, char *path)
{
	int		res;

	res = check_input(input);
	if (res == 0)
		// TODO Changer la fonction par le bon cut
		ft_rush02(input, path);
	else
		write(1, "Error\n", 6);
	return (res);
}

void	read_user_input(char *path)
{
	char	buf[100];
	int		i;

	while (buf > 0)
	{
		read(0, buf, sizeof(buf));
		i = 99;
		while (buf[i] != '\n')
			i--;
		buf[i] = '\0';
		i = 0;
		write_num(buf, path);
		while (i < 100)
		{
			buf[i] = '\0';
			i++;
		}
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int		res;
	char	*input;
	char	*path;

	res = 0;
	if (argc == 2 || argc == 3)
	{
		path = "numbers.dict";
		if (argc == 2)
			input = argv[1];
		else
		{
			input = argv[2];
			path = argv[1];
		}
		if (ft_strcmp(input, "-") == 0)
			read_user_input(path);
		else
			write_num(input, path);
	}
	else
		res = 1;
	if (res != 0)
		write(1, "Error\n", 6);
	return (res);
}
