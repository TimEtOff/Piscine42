/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:10:55 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/21 17:37:06 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	check_base(char *base)
{
	int	res;
	int	i;
	int	i_check;

	res = 1;
	i = 0;
	i_check = 1;
	if (base[i] == '\0' || base[i + 1] == '\0')
		res = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			res = 0;
		while (base[i_check] != '\0')
		{
			if (i != i_check && base[i] == base[i_check])
				res = 0;
			i_check++;
		}
		i_check = 0;
		i++;
	}
	return (res);
}

void	recursive_write(long nbr, char *base, int base_size)
{
	if (nbr > 0)
	{
		recursive_write(nbr / base_size, base, base_size);
		write(1, &base[nbr % base_size], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	nbr_l;

	nbr_l = (long) nbr;
	base_size = ft_strlen(base);
	if (check_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr_l = -nbr_l;
		}
		recursive_write(nbr_l, base, base_size);
		write(1, "\n", 1);
	}
}

/*#include <limits.h>

int	main(void)
{
	ft_putnbr_base(184516, "poneyvif");
	ft_putnbr_base(INT_MAX, "0123456789ABCDEF");
	ft_putnbr_base(INT_MIN, "01");
	return (0);
}*/
