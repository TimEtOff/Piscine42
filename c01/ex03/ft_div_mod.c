/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:30:38 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/10 18:40:39 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	div;
	int	mod;
	int	*d_p;
	int	*m_p;

	d_p = &div;
	m_p = &mod;
	ft_div_mod(18, 7, d_p, m_p);
	printf("div: %d\n", div);
	printf("mod: %d\n", mod);
}*/
