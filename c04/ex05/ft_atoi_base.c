/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:09:35 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/25 10:43:39 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_negative(char *str, int *index)
{
	int	negatives;

	negatives = 0;
	while (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			negatives++;
		(*index)++;
	}
	return (negatives % 2);
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
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

int	index_in_base(char chr, char *base)
{
	int	ind;

	ind = 0;
	while (base[ind] != '\0')
	{
		if (base[ind] == chr)
			return (ind);
		ind++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int		index;
	int		negative;
	long	res;

	res = 0;
	if (check_base(base))
	{
		index = 0;
		while (str[index] == ' ' || str[index] == '\f' || str[index] == '\n'
			|| str[index] == '\r' || str[index] == '\t' || str[index] == '\v')
			index++;
		negative = ft_is_negative(str, &index);
		while (index_in_base(str[index], base) >= 0)
		{
			res *= ft_strlen(base);
			res += index_in_base(str[index], base);
			index++;
		}
		if (negative)
			res = -res;
	}
	return (res);
}

/*int	main(void)
{
	int	res;

	__builtin_printf("%i\n", ft_atoi_base("  -+ca1f", "0123456789abcdef"));
	__builtin_printf("%i\n", ft_atoi_base("  -+ cha1f", "0123456789abcdef"));
	__builtin_printf("%i\n", ft_atoi_base("vvpepy", "poneyvif"));
	res = ft_atoi_base(" \f  +-+-7FFFFFFF", "0123456789ABCDEF");
	__builtin_printf("%i\n", res);
	res = ft_atoi_base("   -10000000000000000000000000000000", "01");
	__builtin_printf("%i\n", res);
	return (0);
}*/
