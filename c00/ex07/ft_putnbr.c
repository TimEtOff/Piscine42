/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:58:44 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 11:08:58 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

/*int	main(void)
{
	ft_putnbr(751);
	write(1, "\n", 1);
	ft_putnbr(8);
	write(1, "\n", 1);
	ft_putnbr(18452);
	write(1, "\n", 1);
	ft_putnbr(-420);
	write(1, "\n", 1);
	return (0);
}*/
