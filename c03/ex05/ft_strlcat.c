/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:25:58 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/17 15:21:12 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



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
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	if (dest_len < (size - 1))
	{
		while (i < (size - dest_len - 1) && src[i] != '\0')
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
		return (dest_len + src_len);
	}
	else
		return (dest_len + size + 1);

}

#include <stdio.h>
#include <bsd/string.h>

// Needs to compile with `-lbsd` flag
int	main(void)
{
	char	src[] = "This is a test";
	char	dest[100] = "Already here ";
	char	src2[] = "This is a test";
	char	dest2[100] = "Already here ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strlcat:	%i\n", ft_strlcat(dest, src, 26));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strlcat:	%zu\n", strlcat(dest2, src2, 26));
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	return (0);
}
