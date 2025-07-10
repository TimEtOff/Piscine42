/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:38:21 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 11:54:27 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_is_negative(int a)
{
	char	res;

	if (a >= 0)
		res = 'P';
	else
		res = 'N';
	write (1, &res, 1);
}

/*
int	main(void)
{
	ft_is_negative(7);
	ft_is_negative(-42);
	ft_is_negative(INT_MAX);
	ft_is_negative(INT_MIN);
}*/
