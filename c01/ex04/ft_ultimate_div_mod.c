/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:43:48 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 18:49:38 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a_val;
	int	b_val;

	a_val = *a;
	b_val = *b;
	*a = a_val / b_val;
	*b = a_val % b_val;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*a_p;
	int	*b_p;

	a = 18;
	b = 7;
	a_p = &a;
	b_p = &b;
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("--- ft_ultimate_div_mod\n");
	ft_ultimate_div_mod(a_p, b_p);
	printf("a: %d\n", a);
	printf("b: %d\n", b);
}*/
