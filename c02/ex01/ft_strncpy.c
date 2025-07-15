/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:07:55 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 10:57:06 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

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

	if (ft_strlen(dest) < n)
		return (dest);
	i = 0;
	while (i < (n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "        ";
	char	src2[] = "This is a test";
	char	dest2[] = "        ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strncpy:	%s\n", ft_strncpy(dest, src, 8));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strncpy:	%s\n", strncpy(dest2, src2, 8));
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
}*/
