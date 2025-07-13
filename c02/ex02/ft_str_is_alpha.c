/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:14:00 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 15:29:38 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	res;

	res = 1;
	while (*str != '\0')
	{
		if (!((((int) 'a' <= (int) *str) && ((int) *str <= (int) 'z'))
				|| (((int) 'A' <= (int) *str) && ((int) *str <= (int) 'Z'))
				|| (((int) '0' <= (int) *str) && ((int) *str <= (int) '9'))
			)
		)
			res = 0;
		str++;
	}
	return (res);
}

/*int	main(void)
{
	printf("%i\n", ft_str_is_alpha("Tdfhfzhzd"));
	printf("%i\n", ft_str_is_alpha("This is only alphanumeric chars"));
	printf("%i\n", ft_str_is_alpha("This is only 161650 chars"));
	printf("%i\n", ft_str_is_alpha("This is not only #$$@$& chars"));
}*/
