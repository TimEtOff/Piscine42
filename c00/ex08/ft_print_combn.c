/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:19:20 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 17:19:18 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb, int s)
{
	char	c;
	int		i;

	c = (char)(nb % 10 + 48);
	if (nb >= 10)
		ft_putnbr(nb / 10, s - 1);
	else
	{
		i = 1;
		while (i < s)
		{
			write(1, "0", 1);
			i++;
		}
	}
	write(1, &c, 1);
}

int	ft_power(int n, int p)
{
	int	res;
	int	i;

	res = n;
	i = 1;
	while (i < p)
	{
		res *= n;
		i++;
	}
	return (res);
}

void	ft_print_comb(int n)
{
	int	i;

	if (!(0 < n && n < 10))
		return ;
	i = 1;
	while (i < ft_power(10, n))
	{
		ft_putnbr(i, n);
		if (i < ft_power(10, n) - 1)
			write(1, ", ", 2);
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb(2);
	return (0);
}*/
