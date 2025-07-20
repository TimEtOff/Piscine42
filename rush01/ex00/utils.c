/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:09:20 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/20 16:19:54 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

int	ft_down_to_one(int nb)
{
	if (nb < 0)
		nb += -nb - 1;
	else if (nb > 0)
		nb += -nb + 1;
	return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = 0;
	while (res == 0 || (*s1 == '\0' && *s2 == '\0'))
	{
		if (*s1 != *s2)
			res = (int) *s1 - (int) *s2;
		else if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (ft_down_to_one(res));
}
