/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:47:50 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/29 21:57:25 by tgodefro         ###   ########lyon.fr   */
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
