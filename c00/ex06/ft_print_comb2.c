/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:01:53 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 16:31:01 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	numbers1[2];
	char	numbers2[2];

	numbers1[0] = '0';
	numbers1[1] = '0';
	numbers2[0] = '0';
	numbers2[1] = '1';

	while (numbers1[0] <= '9')
	{
		while (numbers1[1] <= '9')
		{
			while (numbers2[0] <= '9')
			{
				while (numbers2[1] <= '9')
				{
					if (numbers1[0] + numbers1[1] != numbers2[0] + numbers2[1])
					{
						write(1, numbers1, 2);
						write(1, " ", 1);
						write(1, numbers2, 2);
						write(1, ", ", 2);
					}
					numbers2[1] ++;
				}
				numbers2[1] = '0';
				numbers2[0] ++;
			}
			numbers2[0] = '0';
			numbers1[1] ++;
		}
		numbers1[1] = '0';
		numbers1[0] ++;
	}

}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
