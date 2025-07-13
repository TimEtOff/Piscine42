/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:07:55 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 15:12:24 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i != n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/*int	main(void)
{
	char	src[] = "This is a test";
	char	dest[] = "";

	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
	printf("ft_strcpy: %s\n", ft_strncpy(dest, src, 14));
	printf("src:	%s\n", src);
	printf("dest:	%s\n", dest);
}*/
