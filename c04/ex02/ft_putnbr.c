/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:58:44 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/24 10:07:06 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	From `c00/ex07`
*/
void	ft_putnbr(int nb)
{
	char	c;
	long	nbl;

	nbl = (long) nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	c = (char)(nbl % 10 + 48);
	if (nbl >= 10)
		ft_putnbr(nbl / 10);
	write(1, &c, 1);
}
