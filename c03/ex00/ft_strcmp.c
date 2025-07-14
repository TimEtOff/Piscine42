/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:47:50 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 18:27:59 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = 0;
	while (res == 0 || *s1 == '\0' || *s2 == '\0')
	{
		if (*s1 != *s2)
			res = (int) *s1 - (int) *s2;
		s1++;
		s2++;
	}
	return (res);
}

int	main(void)
{
	printf("%i\n", ft_strcmp("Test", "Tast"));
	printf("%i\n", ft_strcmp("oui", "nope"));
	printf("%i\n", ft_strcmp("oui", "ouiii"));
	printf("%i\n", ft_strcmp("noooon", "noo"));
	printf("%i\n", ft_strcmp("Test", "Test"));
	printf("\n");
	printf("%i\n", strcmp("Test", "Tast"));
	printf("%i\n", strcmp("oui", "nope"));
	printf("%i\n", strcmp("oui", "ouiii"));
	printf("%i\n", strcmp("noooon", "noo"));
	printf("%i\n", strcmp("Test", "Test"));
}
