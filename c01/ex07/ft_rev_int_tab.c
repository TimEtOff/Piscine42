/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:35:47 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/11 10:02:23 by tgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i <= size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i] = temp;
		i++;
	}
}

/*void	print_tab(int *tab, int len)
{
	int	i;

	i = 0;
	printf("%c", '{');
	while (i < len-1)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	printf("%d}\n", tab[i]);
}

int	main(void)
{
	int	tab[6] = {0, 1, 2, 3, 4, 5};

	print_tab(tab, 6);
	ft_rev_int_tab(tab, 6);
	print_tab(tab, 6);
}*/
