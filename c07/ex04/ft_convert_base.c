/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:59:04 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/25 14:18:23 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_atoi_base(char *str, char *base);
int		check_base(char *base);
int		ft_strlen(char *str);

void	str_append_char(char *str, char append)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(str);
	i = 0;
	str[str_len] = append;
	str[str_len + 1] = '\0';
}

void	recursive_write(long nbr, char *base, int base_size, char *res)
{
	if (nbr > 0)
	{
		if (nbr > 0)
			recursive_write(nbr / base_size, base, base_size, res);
		str_append_char(res, base[nbr % base_size]);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	atoied_nbr;
	int		base_size;
	char	*res;

	if (!check_base(base_to))
		return (NULL);
	atoied_nbr = ft_atoi_base(nbr, base_from);
	base_size = ft_strlen(base_to);
	res = "";
	if (check_base(base_to)
		&& -2147483648 <= atoied_nbr && atoied_nbr <= 2147483647)
	{
		res = malloc(sizeof(char) * 100);
		res[0] = '\0';
		if (atoied_nbr < 0)
		{
			str_append_char(res, '-');
			atoied_nbr = -atoied_nbr;
		}
		recursive_write(atoied_nbr, base_to, base_size, res);
	}
	else
		return (NULL);
	return (res);
}

/*int	main(void)
{
	char	*res;

	res = ft_convert_base(" -+--80000000hy", "0123456789ABCDEF", "01");
	__builtin_printf("%s\n", res);
	res = ft_convert_base("   +---++-lX", "XavNiel", "0123456789");
	__builtin_printf("%s\n", res);
	free(res);
	return (0);
}*/
