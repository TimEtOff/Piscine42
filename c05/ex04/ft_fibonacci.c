/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:37:29 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/22 10:49:45 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	res;

	if (index <= 0)
		res = 0;
	else if (index == 1)
		res = 1;
	else
		res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_fibonacci(6));
	return (0);
}*/
