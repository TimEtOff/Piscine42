/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:42:06 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 15:42:07 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

/*
	In ASCII table, printable characters are all
	charactes between 32 and 126 (Alphanumeric and punctuation chars)
*/

int	ft_str_is_printable(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((32 <= (int) *str) && ((int) *str <= 126)))
			res = 0;
		str++;
	}
	return (res);
}

/*int	main(void)
{
	printf("%i\n", ft_str_is_printable("Tdfhfzhzd"));
	printf("%i\n", ft_str_is_printable("This is only alphanumeric chars"));
	printf("%i\n", ft_str_is_printable("This is only 161650 chars"));
	printf("%i\n", ft_str_is_printable("This is not only #$$@$& chars"));
}*/
