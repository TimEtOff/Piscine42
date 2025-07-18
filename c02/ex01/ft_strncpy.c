/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:07:55 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/18 14:01:24 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Edited version from `c01/ex06/ft_strlen.c`
*/
unsigned int	ft_strlen(char *str)
{
	unsigned int	nbr;

	nbr = 0;
	while (*str != '\0')
	{
		nbr++;
		str++;
	}
	return (nbr);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello world";
	char	dest[100];
	char	src2[] = "Hello world";
	char	dest2[100];

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strncpy:	%s\n", ft_strncpy(dest, src, 5));
	//printf("c:			%i\n", dest[12]);
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strncpy:	%s\n", strncpy(dest2, src2, 5));
	//printf("c:			%i\n", dest2[12]);
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
}*/
