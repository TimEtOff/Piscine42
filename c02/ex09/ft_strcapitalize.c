/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:00:31 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/16 15:05:16 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Modified version of `ex04/ft_str_is_lowercase`
*/
int	ft_char_is_lowercase(char c)
{
	int	res;

	res = 1;
	if (!(((int) 'a' <= (int) c) && ((int) c <= (int) 'z')))
		res = 0;
	return (res);
}

/*
	Imported from `ex08/ft_strlowcase.c`
*/
char	*ft_strlowcase(char *str)
{
	int	i;
	int	diff;

	i = 0;
	diff = (int) 'a' - (int) 'A';
	while (*str != '\0')
	{
		if (((int) 'A' <= (int) *str) && ((int) *str <= (int) 'Z'))
			*str = (char)(((int) *str) + diff);
		str++;
		i++;
	}
	while (i > 0)
	{
		str--;
		i--;
	}
	return (str);
}

/*
	Modified version of `ex02/ft_str_is_alpha`
*/
int	ft_char_is_alphanum(char c)
{
	int	res;

	res = 1;
	if (!((((int) 'a' <= (int) c) && ((int) c <= (int) 'z'))
			|| (((int) 'A' <= (int) c) && ((int) c <= (int) 'Z'))
			|| (((int) '0' <= (int) c) && ((int) c <= (int) '9'))
		)
	)
		res = 0;
	return (res);
}

char	*ft_decrement_str(char *str, int len)
{
	while (len > 0)
	{
		str--;
		len--;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	diff;
	int	capitalize_next;

	i = 0;
	diff = (int) 'a' - (int) 'A';
	capitalize_next = 1;
	ft_strlowcase(str);
	while (*str != '\0')
	{
		if (capitalize_next && ft_char_is_alphanum(*str))
		{
			if (ft_char_is_lowercase(*str))
				*str = (char)(((int) *str) - diff);
			capitalize_next = 0;
		}
		else if (!(ft_char_is_alphanum(*str)))
			capitalize_next = 1;
		str++;
		i++;
	}
	return (ft_decrement_str(str, i));
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "This is a+test";
	char	str2[] = "and AnotHer";

	printf("%s\n", str);
	printf("%s\n", ft_strcapitalize(str));
	printf("%s\n", str2);
	printf("%s\n", ft_strcapitalize(str2));
}*/
