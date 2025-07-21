/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:16:15 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/21 18:21:19 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power < 0)
		res = 0;
	else if (power == 0)
		res = 1;
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
	}
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_recursive_power(2, 8));
}*/
