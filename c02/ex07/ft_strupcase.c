/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:15:45 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/14 10:52:51 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;
	int	diff;

	i = 0;
	diff = (int) 'a' - (int) 'A';
	while (*str != '\0')
	{
		if (((int) 'a' <= (int) *str) && ((int) *str <= (int) 'z'))
		{
			*str = (char)(((int) *str) - diff);
		}
		str++;
		i++;
	}
	while (i > 0)
	{
		str--;
		i--;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "This is a test";

	printf("%s\n", str);
	printf("%s\n", ft_strupcase(str));
}*/
