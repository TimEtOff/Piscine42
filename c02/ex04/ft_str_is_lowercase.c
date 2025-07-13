/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:34:10 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 15:36:18 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((((int) 'a' <= (int) *str) && ((int) *str <= (int) 'z'))))
		{
			res = 0;
		}
		str++;
	}
	return (res);
}

/*int	main(void)
{
	printf("%i\n", ft_str_is_lowercase("Tdfhfzhzd"));
	printf("%i\n", ft_str_is_lowercase("thisisonlylowecasechars"));
	printf("%i\n", ft_str_is_lowercase("This is only 161650 chars"));
	printf("%i\n", ft_str_is_lowercase("This is not only #$$@$& chars"));
}*/

