/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:19:40 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/16 18:14:47 by tgodefro         ###   ########lyon.fr   */
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

/*
	Imported from `ex11/ft_putstr_non_printable`.
*/
void	ft_put_hex_from_int(long nb, int size)
{
	char	*hex_nbrs;
	char	print;

	hex_nbrs = "0123456789abcdef";
	if ((nb >= 16 && size > 1) || size > 1)
		ft_put_hex_from_int(nb / 16, size - 1);
	if (nb < 0)
		print = '0';
	else
		print = hex_nbrs[nb % 16];
	write(1, &print, 1);
}

/*
	Edited from `ex06/ft_str_is_printable`
*/
int	ft_char_is_printable(char chr)
{
	int	res;

	res = 1;
	if (!((32 <= chr) && (chr <= 126)))
		res = 0;
	return (res);
}

void	ft_print_line(char *str, int line, int size)
{
	char	print_chars[17];
	int		index;

	index = 0;
	while (index < 16)
	{
		if (index < size)
		{
			print_chars[index] = (unsigned char) str[(16 * line + index)];
			ft_put_hex_from_int((long)(unsigned char) print_chars[index], 2);
			if (!ft_char_is_printable((unsigned char) print_chars[index]))
				print_chars[index] = '.';
		}
		else
		{
			ft_putstr("  ");
			print_chars[index] = '\0';
		}
		if (index % 2 == 1)
			ft_putstr(" ");
		index++;
	}
	ft_putstr(print_chars);
	ft_putstr("\n");
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	line;
	char			*str;
	int				left;

	str = (char *) addr;
	line = 0;
	left = size;
	if (size == 0)
		return (addr);
	while (line <= (size / 16))
	{
		ft_put_hex_from_int((long) &addr + (16 * line), 16);
		ft_putstr(": ");
		ft_print_line(str, line, left);
		left -= 16;
		line++;
	}
	return (addr);
}

/*int	main(void)
{
	char	*str;
	int		test[] = {1, 2, 8, 6, 7, 3, 4, 2, 8, 0, 3};

	str = "This is a test string for displaying¡¿ the memory area";
	ft_print_memory(str, 250);
	ft_putstr("\n");
	str = "abcdefghijklmnopqrstuvwxyz0123456789";
	ft_print_memory(str, 37);
	ft_putstr("\n");
	ft_print_memory(test, 92);
}*/
