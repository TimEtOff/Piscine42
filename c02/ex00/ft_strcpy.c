/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:24:34 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 09:24:37 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
From `man strcpy`:
> The strcpy() function copies the string pointed to by src,
> including the terminating null byte ('\0'), to the buffer pointed to by dest.
> The strings may not overlap, and the destination string dest must be large
> enough to receive the copy.
*/
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "";

	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
	printf("ft_strcpy: %s\n", ft_strcpy(dest, src));
	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
}
