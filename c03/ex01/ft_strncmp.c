/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:28:19 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 10:35:51 by tgodefro         ###   ########lyon.fr   */
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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (i < n)
	{
		if (*s1 != *s2 && res == 0)
			res = (int) *s1 - (int) *s2;
		s1++;
		s2++;
		i++;
	}

	return (ft_down_to_one(res));
}

/*int	main(void)
{
	printf("%i\n", ft_strncmp("Tast", "Test", 4));
	printf("%i\n", ft_strncmp("oui", "nope", 8));
	printf("%i\n", ft_strncmp("oui", "ouiii", 3));
	printf("%i\n", ft_strncmp("noooon", "noo", 5));
	printf("%i\n", ft_strncmp("Test", "Test", 5));
	printf("%i\n", ft_strncmp(" ", "", 0));
	printf("\n");
	printf("%i\n", strncmp("Tast", "Test", 4));
	printf("%i\n", strncmp("oui", "nope", 8));
	printf("%i\n", strncmp("oui", "ouiii", 3));
	printf("%i\n", strncmp("noooon", "noo", 5));
	printf("%i\n", strncmp("Test", "Test", 5));
	printf("%i\n", strncmp(" ", "", 0));
}*/
