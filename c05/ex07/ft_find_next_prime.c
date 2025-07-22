/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:42 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/22 14:37:09 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	res;
	int	ind;

	res = 1;
	ind = 2;
	if (nb <= 1)
		return (0);
	while (ind < nb && res == 1)
	{
		if (nb % ind == 0)
			res = 0;
		ind++;
	}
	return (res);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%i: %i\n", 27, ft_find_next_prime(27));
	printf("%i: %i\n", INT_MAX, ft_find_next_prime(INT_MAX));
	printf("%i: %i\n", INT_MIN, ft_find_next_prime(INT_MIN));
	return (0);
}*/
