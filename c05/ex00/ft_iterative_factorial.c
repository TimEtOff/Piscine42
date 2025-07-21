/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:47:18 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/21 17:55:19 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = nb;
	nb--;
	while (nb >= 1)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_iterative_factorial(10));
	return (0);
}*/
