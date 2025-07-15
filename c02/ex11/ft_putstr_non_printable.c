/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:05:31 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/15 16:15:19 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_int_to_hex(int nb)
{

}

/*
	Imported from `c01/ex06`
*/
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

/*
	Edited from `ex06`
*/
int	ft_str_is_printable(char chr)
{
	int	res;

	res = 1;
	if (!((32 <= (int) chr) && ((int) chr <= 126)))
		res = 0;
	return (res);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if ()
		write(1, str, 1);
		str++;
	}
}
