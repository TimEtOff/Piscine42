/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:31:43 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 15:33:04 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((((int) '0' <= (int) *str) && ((int) *str <= (int) '9'))))
		{
			res = 0;
		}
		str++;
	}
	return (res);
}

/*int	main(void)
{
	printf("%i\n", ft_str_is_numeric("Tdfhfzhzd"));
	printf("%i\n", ft_str_is_numeric("This is only alphanumeric chars"));
	printf("%i\n", ft_str_is_numeric("This is only 161650 chars"));
	printf("%i\n", ft_str_is_numeric("This is not only #$$@$& chars"));
	printf("%i\n", ft_str_is_numeric("144616468512"));
}*/
