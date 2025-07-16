/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:31:04 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/16 18:12:20 by tgodefro         ###   ########lyon.fr   */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/*#include <stdio.h>
#include <bsd/string.h>

//Needs to compile with `-lbsd` flag
int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "        ";
	char	src2[] = "This is a test";
	char	dest2[] = "        ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strlcpy:	%i\n", ft_strlcpy(dest, src, 0));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strlcpy:	%zu\n", strlcpy(dest2, src2, 0));
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
}*/
