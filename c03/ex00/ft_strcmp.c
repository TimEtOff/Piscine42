/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:47:50 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 10:24:22 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

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

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = 0;
	while (res == 0 || (*s1 == '\0' && *s2 == '\0'))
	{
		if (*s1 != *s2)
			res = (int) *s1 - (int) *s2;
		else if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
	}

	return (ft_down_to_one(res));
}

/*int	main(void)
{
	printf("%i\n", ft_strcmp("Test", "Tast"));
	printf("%i\n", ft_strcmp("oui", "nope"));
	printf("%i\n", ft_strcmp("oui", "ouiii"));
	printf("%i\n", ft_strcmp("noooon", "noo"));
	printf("%i\n", ft_strcmp("Test", "Test"));
	printf("%i\n", ft_strcmp(" ", ""));
	printf("\n");
	printf("%i\n", strcmp("Test", "Tast"));
	printf("%i\n", strcmp("oui", "nope"));
	printf("%i\n", strcmp("oui", "ouiii"));
	printf("%i\n", strcmp("noooon", "noo"));
	printf("%i\n", strcmp("Test", "Test"));
	printf("%i\n", strcmp(" ", ""));
}*/
