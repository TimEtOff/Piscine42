/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:31:04 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 17:41:50 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

/*
	Imported from `c01/ex06/ft_strlen`
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

char	*ft_decrement_str(char *str, int len)
{
	while (len > 0)
	{
		str--;
		len--;
	}
	return (str);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = ft_strlen(src);
	while (i < (size - 1))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (res);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "";

	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
	printf("ft_strcpy: %i\n", ft_strlcpy(dest, src, 10));
	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
}*/
