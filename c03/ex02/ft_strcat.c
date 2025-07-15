/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:13:36 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 13:53:00 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strcat(char *dest, char *src)
{
	int	dest_index;
	int	src_index;

	dest_index = 0;
	while (dest[dest_index] != '\0')
		dest_index++;
	src_index = 0;
	while (src[src_index] != '\0')
	{
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = src[src_index];
	return (dest);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "Already here ";
	char	src2[] = "This is a test";
	char	dest2[] = "Already here ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strcpy:	%s\n", ft_strcat(dest, src));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("\n");
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	printf("strcpy:		%s\n", strcat(dest2, src2));
	printf("src2:		%s\n", src2);
	printf("dest2:		%s\n", dest2);
	return (0);
}*/
