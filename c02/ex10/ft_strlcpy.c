/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:31:04 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 11:49:37 by tgodefro         ###   ########.fr       */
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
	src--;
	*dest = '\n';
	return (res);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "";

	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
	printf("ft_strcpy: %i\n", ft_strlcpy(dest, src, 20));
	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
}*/
