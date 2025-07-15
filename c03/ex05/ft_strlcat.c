/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:25:58 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 16:39:33 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <bsd/string.h>*/

/*
	Imported from `c01/ex06`
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_index;
	unsigned int	src_index;
	int				res;

	dest_index = 0;
	res = ft_strlen(dest) + ft_strlen(src);
	while (dest[dest_index] != '\0')
		dest_index++;
	src_index = 0;
	while ((dest_index + src_index) < size - 1)
	{
		if (src[src_index] == '\0')
			break ;
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = '\0';
	return (res);
}

/*
	Needs to compile with `-lbsd` flag
*/
/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "Already here ";
	char	src2[] = "This is a test";
	char	dest2[] = "Already here ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strlcat:	%i\n", ft_strlcat(dest, src, 20));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strlcat:	%zu\n", strlcat(dest2, src2, 20));
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	return (0);
}*/
