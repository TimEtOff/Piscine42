/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:00:31 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 11:24:13 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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
	Modified version of `ex02/ft_str_is_alpha`
*/
int	ft_char_is_alpha(char c)
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
	while (*str != '\0')
	{
		if (capitalize_next && ft_char_is_alpha(*str))
		{
			if (ft_char_is_lowercase(*str))
				*str = (char)(((int) *str) - diff);
			capitalize_next = 0;
		}
		else if (!(ft_char_is_alpha(*str)))
			capitalize_next = 1;
		str++;
		i++;
	}
	return (ft_decrement_str(str, i));
}

/*int	main(void)
{
	char	str[] = "This is a+test";
	char	str2[] = "and Another";

	printf("%s\n", str);
	printf("%s\n", ft_strcapitalize(str));
	printf("%s\n", str2);
	printf("%s\n", ft_strcapitalize(str2));
}*/
