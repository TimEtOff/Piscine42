/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:39:34 by mboutte           #+#    #+#             */
/*   Updated: 2025/07/23 12:18:59 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	dest = malloc(sizeof(char) * (len));
	if (!dest)
		return (NULL);
	len = -1;
	while (src[++len])
		dest[len] = src[len];
	dest[len] = '\0';
	return (dest);
}

/*#include <string.h>
int	main(void)
{
	char	str1[] = "test";
	char	*dest;

	dest = ft_strdup(str1);
	str1[0] = '0';
	__builtin_printf("%s", ft_strdup(dest));
	__builtin_printf("\n%s", ft_strdup(str1));
	return (0);
}*/
