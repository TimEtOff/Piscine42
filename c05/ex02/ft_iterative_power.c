/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:03:47 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/21 18:15:11 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		res = 0;
	else
	{
		res = 1;
		while (power > 0)
		{
			res *= nb;
			power--;
		}
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_iterative_power(2, 0));
}
