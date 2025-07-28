/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:56:22 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/24 10:36:54 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_is_negative(char *str, int *index)
{
	int	negatives;

	negatives = 0;
	while (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			negatives++;
		(*index)++;
	}
	return (negatives % 2);
}

int	ft_atoi(char *str)
{
	int		index;
	int		negative;
	long	res;

	index = 0;
	while (str[index] == ' ' || str[index] == '\f' || str[index] == '\n'
		|| str[index] == '\r' || str[index] == '\t' || str[index] == '\v')
		index++;
	negative = ft_is_negative(str, &index);
	res = 0;
	while (ft_char_is_numeric(str[index]))
	{
		res = res * 10;
		res += str[index] - 48;
		index++;
	}
	if (negative)
		res = -res;
	return (res);
}

/*int	main(void)
{
	__builtin_printf("%d\n", ft_atoi("   ---+--+1234ab567"));
	__builtin_printf("%d\n", ft_atoi(" \t  ---+- -+1234ab567"));
	__builtin_printf("%d\n", ft_atoi("  \v ++--+-+-+2147483647"));
	__builtin_printf("%d\n", ft_atoi("   ---+--+-+-2147483648"));
	return (0);
}*/
