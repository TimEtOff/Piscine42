/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:10:00 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 18:29:02 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*a_p;
	int	*b_p;

	a = 42;
	a_p = &a;
	b = 69;
	b_p = &b;
	printf("a: %d\n", *a_p);
	printf("a_p: %p\n", a_p);
	printf("b: %d\n", *b_p);
	printf("b_p: %p\n", b_p);
	printf("--- ft_swap\n");
	ft_swap(a_p, b_p);
	printf("a: %d\n", *a_p);
	printf("a_p: %p\n", a_p);
	printf("b: %d\n", *b_p);
	printf("b_p: %p\n", b_p);
}*/
