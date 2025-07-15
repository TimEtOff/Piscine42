/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:05:31 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 17:15:43 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (ft_char_is_printable(*str))
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			ft_put_hex_from_int(*str, 2);
		}
		str++;
	}
}

/*int	main(void)
{
	char	*str;

	str = "Hello\nHow are you?";
	ft_putstr_non_printable(str);
	return (0);
}*/
