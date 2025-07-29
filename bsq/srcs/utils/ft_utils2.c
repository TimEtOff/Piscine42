/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:18:24 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/29 16:34:07 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_utils.h"

int	ft_min(int first_int, int second_int, int third_int)

{
	int	res;

	if (first_int < second_int)
		res = first_int;
	else
		res = second_int;
	if (res > third_int)
		res = third_int;
	return (res);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
	In ASCII table, printable characters are all
	charactes between 32 and 126 (Alphanumeric and punctuation chars)
*/
int	ft_str_is_printable(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((32 <= (int) *str) && ((int) *str <= 126)))
			res = 0;
		str++;
	}
	return (res);
}

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
