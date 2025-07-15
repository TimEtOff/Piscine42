/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:25:58 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 15:55:51 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_index;
	unsigned int	src_index;

	dest_index = 0;
	while (dest[dest_index] != '\0')
		dest_index++;
	src_index = 0;
	while (src_index < nb)
	{
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = '\0';
	return (dest_index + src_index);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "Already here ";

	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	printf("ft_strlcat:	%i\n", ft_strlcat(dest, src, 6));
	printf("src:		%s\n", src);
	printf("dest:		%s\n", dest);
	return (0);
}*/
