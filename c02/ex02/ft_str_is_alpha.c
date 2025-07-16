/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:14:00 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/16 15:00:47 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((('a' <= *str) && (*str <= 'z'))
				|| (('A' <= *str) && (*str <= 'Z'))
			)
		)
			res = 0;
		str++;
	}
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_str_is_alpha("Tdfhfzhzd"));
	printf("%i\n", ft_str_is_alpha("This is only alphanumeric chars"));
	printf("%i\n", ft_str_is_alpha("This is only 161650 chars"));
	printf("%i\n", ft_str_is_alpha("Tdfh951fzhzd"));
	printf("%i\n", ft_str_is_alpha("This is not only #$$@$& chars"));
}*/
