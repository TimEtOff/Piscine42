/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:32:07 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 10:33:37 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	ch;
	int		index;
	int		end;

	index = (int) '0';
	end = index + 10;
	while (index != end)
	{
		ch = (char) index;
		write(1, &ch, 1);
		index ++;
	}
}

//int	main(void)
//{
//	ft_print_numbers();
//}
