/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:40 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/22 14:28:04 by tgodefro         ###   ########lyon.fr   */
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

/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%i: %i\n", 27, ft_is_prime(27));
	printf("%i: %i\n", INT_MAX, ft_is_prime(INT_MAX));
	printf("%i: %i\n", INT_MIN, ft_is_prime(INT_MIN));
	return (0);
}*/
