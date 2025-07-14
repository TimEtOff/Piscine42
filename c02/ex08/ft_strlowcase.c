/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:57:09 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 11:03:03 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*int	main(void)
{
	char	str[] = "This is a test";
	char	str2[] = "AND ANOthEr";

	printf("%s\n", str);
	printf("%s\n", ft_strlowcase(str));
	printf("%s\n", str2);
	printf("%s\n", ft_strlowcase(str2));
}*/
