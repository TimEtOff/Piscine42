/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:51:38 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 15:23:40 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <string.h>

/*
	Imported from `c01/ex06/ft_strlen.c`
*/
int	ft_strlen(char *str)
{
	int	nbr;

	nbr = 0;
	while (*str != '\0')
	{
		nbr++;
		str++;
	}
	return (nbr);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*res;
	int		find_index;

	res = NULL;
	find_index = 0;
	while (*str != '\0')
	{
		if (find_index <= (ft_strlen(to_find) - 1))
		{
			if (*str == to_find[find_index])
			{
				if (find_index == 0)
					res = str;
				find_index++;
			}
			else
			{
				find_index = 0;
				res = NULL;
			}
		}
		str++;
	}
	return (res);
}

/*int	main(void)
{
	printf("%s\n", ft_strstr("J'adore42 c'est super", "42"));
	printf("%s\n", strstr("J'adore42 c'est super", "42"));
	printf("%s\n", ft_strstr("J'adore42 c'est super", "J'adore"));
	printf("%s\n", strstr("J'adore42 c'est super", "J'adore"));
	printf("%s\n", ft_strstr("J'adore42 c'est super", "er"));
	printf("%s\n", strstr("J'adore42 c'est super", "er"));
	printf("%s\n", ft_strstr("", "42"));
	printf("%s\n", strstr("", "42"));
	return (0);
}*/
