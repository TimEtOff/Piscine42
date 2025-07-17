/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:51:38 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/17 14:21:29 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

	find_index = 0;
	if (*to_find == '\0')
		return (str);
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
				find_index = 0;
		}
		str++;
	}
	if (find_index == 0)
		res = NULL;
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strstr("I love 42 It's awesome", "42"));
	printf("%s\n", strstr("I love 42 It's awesome", "42"));
	printf("%s\n", ft_strstr("I love 42 It's awesome", "I love"));
	printf("%s\n", strstr("I love 42 It's awesome", "I love"));
	printf("%s\n", ft_strstr("I love 42 It's awesome", "ome"));
	printf("%s\n", strstr("I love 42 It's awesome", "ome"));
	printf("%s\n", ft_strstr("", "42"));
	printf("%s\n", strstr("", "42"));
	printf("%s\n", ft_strstr("I love 42 It's awesome", ""));
	printf("%s\n", strstr("I love 42 It's awesome", ""));
	printf("%s\n", ft_strstr("", ""));
	printf("%s\n", strstr("", ""));
	return (0);
}*/
