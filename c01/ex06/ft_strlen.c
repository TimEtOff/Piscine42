/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:29:34 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/11 09:29:35 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*int	main(void)
{
	printf("%d\n", ft_strlen("Test"));
	printf("%d\n", ft_strlen("42"));
	printf("%d\n", ft_strlen("AAAAAAAAAAAAAAAAAAAAAAAAAaaaaaaaaaaaaaah"));
}*/
