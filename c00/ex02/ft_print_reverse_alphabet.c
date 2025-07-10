/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:24:33 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 10:30:38 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	ch;
	int		index;
	int		end;

	index = (int) 'z';
	end = index - 26;
	while (index != end)
	{
		ch = (char) index;
		write(1, &ch, 1);
		index --;
	}
}

/*int	main(void)
{
	ft_print_reverse_alphabet();
}*/
