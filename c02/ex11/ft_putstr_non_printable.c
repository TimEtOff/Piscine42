/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:05:31 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/16 18:12:00 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
int	ft_char_is_printable(unsigned char chr)
{
	int	res;

	res = 1;
	if (!((32 <= (int) chr) && ((int) chr <= 126)))
		res = 0;
	return (res);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (ft_char_is_printable((unsigned char) *str))
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			ft_put_hex_from_int((unsigned char) *str, 2);
		}
		str++;
	}
}

/*int	main(void)
{
	char	*str;

	str = "Hello\nHow are you?Â\xff¡";
	ft_putstr_non_printable(str);
	return (0);
}*/
