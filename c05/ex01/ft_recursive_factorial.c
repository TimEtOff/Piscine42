/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:58:28 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/21 18:01:07 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb > 1)
		res *= ft_recursive_factorial(nb - 1);
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_recursive_factorial(10));
	return (0);
}*/
