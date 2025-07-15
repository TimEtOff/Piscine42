/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:31:04 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 16:04:48 by tgodefro         ###   ########lyon.fr   */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (src_len < size)
		return (src_len);
	i = 0;
	while (i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	return (src_len);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "        ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strlcpy:	%i\n", ft_strlcpy(dest, src, 8));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
}*/
