/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:55 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/17 13:56:19 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "Already here ";
	char	src2[] = "This is a test";
	char	dest2[] = "Already here ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strncat:	%s\n", ft_strncat(dest, src, 0));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strncat:	%s\n", strncat(dest2, src2, 0));
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	return (0);
}*/
