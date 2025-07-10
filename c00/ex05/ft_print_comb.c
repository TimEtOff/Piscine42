/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:11:25 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 15:59:57 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	str[3];

	str[0] = '0';
	str[1] = '1';
	str[2] = '2';
	while ((int) str[0] <= (int) '7')
	{
		while ((int) str[1] <= (int) '8')
		{
			while ((int) str[2] <= (int) '9')
			{
				write(1, str, 3);
				if (!(str[0] == '7' && str[1] == '8' && str[2] == '9'))
					write(1, ", ", 2);
				str[2]++;
			}
			str[1]++;
			if (str[2] == '9' + 1)
				str[2] = str[1] + 1;
		}
		str[0]++;
		if (str[1] == '8' + 1)
			str[1] = str[0];
	}
}

/*int	main(void)
{
	ft_print_comb();
}*/
