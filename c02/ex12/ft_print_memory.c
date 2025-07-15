/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:19:40 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 18:48:22 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Imported from `ex11/ft_putstr_non_printable`.
*/
void	ft_put_hex_from_int(int nb, int size)
{
	char	*hex_nbrs;

	hex_nbrs = "0123456789abcdef";
	if (nb >= 16 || size > 1)
		ft_put_hex_from_int(nb / 16, size - 1);
	write(1, &hex_nbrs[nb % 16], 1);
}

/*
	Edited from `ex06/ft_str_is_printable`
*/
int	ft_char_is_printable(char chr)
{
	int	res;

	res = 1;
	if (!((32 <= (int) chr) && ((int) chr <= 126)))
		res = 0;
	return (res);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	line;
	unsigned int	index;
	char			*str;

	str = (char *) addr;
	line = 0;
	index = 0;
	while (line <= (size / 16))
	{
		ft_put_hex_from_int((int) str[(16 * line)], 16);
		ft_putstr(": ");
		while (index < 16)
		{
			ft_put_hex_from_int((int) str[(16 * line + index)], 2);
			index++;
		}
		ft_putstr("\n");
		line++;
		index = 0;
	}
	return (addr);
}

int	main(void)
{
	char	*str;

	str = "This is a test string for displaying the memory area";
	ft_print_memory(str, 52);
}
