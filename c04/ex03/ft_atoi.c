/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:56:22 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/24 09:59:06 by tgodefro         ###   ########lyon.fr   */
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
	int		res;

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

/*
// From `c00/ex07`
void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	c = (char)(nb % 10 + 48);
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &c, 1);
}

int	main(void)
{
	ft_putnbr(ft_atoi("   ---+--+1234ab567"));
	return (0);
}*/
