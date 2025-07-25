/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:47:18 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/25 10:02:46 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		res = 0;
	else if (nb == 0)
		res = 1;
	else
	{
		res = nb;
		nb--;
		while (nb >= 1)
		{
			res *= nb;
			nb--;
		}
	}
	return (res);
}

/*int	main(void)
{
	__builtin_printf("%i\n", ft_iterative_factorial(10));
	return (0);
}*/
