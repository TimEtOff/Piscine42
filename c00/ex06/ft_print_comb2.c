/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:01:53 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 16:11:18 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	fr_print_num(int num)
{
	char	c1;
	char	c2;

	c1 = (char)(num / 10 + 48);
	c2 = (char)(num % 10 + 48);
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 00;
	num2 = 00;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			fr_print_num(num1);
			write(1, " ", 1);
			fr_print_num(num2);
			if (num1 != 98)
			{
				write(1, ", ", 2);
			}
			num2++;
		}
		num1++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
