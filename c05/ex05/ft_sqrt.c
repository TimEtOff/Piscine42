/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:25:32 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/22 14:09:04 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	ind;

	ind = 0;
	if (nb < 0)
		return (0);
	while (ind * ind < nb && ind <= 46340)
		ind++;
	if (ind * ind == nb)
		return (ind);
	else
		return (0);
}

/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%i\n", ft_sqrt(4));
	printf("%i\n", ft_sqrt(INT_MAX));
	printf("%i\n", ft_sqrt(INT_MIN));
	return (0);
}*/
