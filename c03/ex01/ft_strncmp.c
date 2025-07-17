/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:28:19 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/17 13:43:32 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Takes an int and return one with the same sign.
	Does nothing if `nb` is equal to 0.
*/
int	ft_down_to_one(int nb)
{
	if (nb < 0)
		nb += -nb - 1;
	else if (nb > 0)
		nb += -nb + 1;
	return (nb);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				res;
	unsigned int	i;
	int				ended;

	res = 0;
	i = 0;
	ended = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] && res == 0 && !ended)
			res = (unsigned char) s1[i] - (unsigned char) s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			ended = 1;
		i++;
	}
	return (ft_down_to_one(res));
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%i\n", ft_strncmp("Tast", "Test", 4));
	printf("%i\n", ft_strncmp("yes", "nope", 8));
	printf("%i\n", ft_strncmp("yee", "yeeeah", 10));
	printf("%i\n", ft_strncmp("noooo", "noo", 3));
	printf("%i\n", ft_strncmp(" ", "", 0));
	printf("%i\n", ft_strncmp("¡tbfsf¼", "¡tbfsf¼", 9));
	printf("%i\n", ft_strncmp("¡tbfsf¼", "¡tbfsf€", 9));
	printf("%i\n", ft_strncmp("zazzzzzz", "zzzzzzzzzzzzz", 50));
	printf("\n");
	printf("%i\n", strncmp("Tast", "Test", 4));
	printf("%i\n", strncmp("yes", "nope", 8));
	printf("%i\n", strncmp("yee", "yeeeah", 10));
	printf("%i\n", strncmp("noooo", "noo", 3));
	printf("%i\n", strncmp(" ", "", 0));
	printf("%i\n", strncmp("¡tbfsf¼", "¡tbfsf¼", 9));
	printf("%i\n", strncmp("¡tbfsf¼", "¡tbfsf€", 9));
	printf("%i\n", strncmp("zazzzzzz", "zzzzzzzzzzzzz", 50));
	return (0);
}*/
