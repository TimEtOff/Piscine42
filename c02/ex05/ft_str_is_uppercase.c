/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:37:21 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 15:37:22 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((((int) 'A' <= (int) *str) && ((int) *str <= (int) 'Z'))))
		{
			res = 0;
		}
		str++;
	}
	return (res);
}

/*int	main(void)
{
	printf("%i\n", ft_str_is_uppercase("Tdfhfzhzd"));
	printf("%i\n", ft_str_is_uppercase("THISISONLYUPPERCASE"));
	printf("%i\n", ft_str_is_uppercase("This is only 161650 chars"));
	printf("%i\n", ft_str_is_uppercase("This is not only #$$@$& chars"));
}*/
