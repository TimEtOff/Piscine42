/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:03:17 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/26 16:34:52 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_find(char *str);

char	*ft_unit(char *str)
{
	char	*res;

	if (ft_strlen(str) == 1 && *str != '0')
		res = ft_find(str);
	else
		res = "";
	return (res);
}

char	*get_temp_ten(char ten)
{
	char	*temp_ten;

	temp_ten = malloc(sizeof(char) * 3);
	temp_ten[0] = ten;
	temp_ten[1] = '0';
	temp_ten[2] = '\0';
	return (temp_ten);
}

char	*make_tens_res(char *ten, char *unit)
{
	char	*res;
	int		ten_len;
	int		unit_len;

	if (ten == 0 || unit == 0)
		return (0);
	ten_len = ft_strlen(ten);
	unit_len = ft_strlen(unit);
	res = malloc(sizeof(char) * (ten_len + unit_len + 2));
	if (res == NULL)
		return (0);
	res[0] = '\0';
	if (ten_len != 0)
	{
		str_append(res, ten);
		str_append(res, " ");
	}
	str_append(res, unit);
	return (res);
}

char	*ft_tens(char *str)
{
	int		size;
	char	*ten;
	char	*temp_ten;
	char	*unit;

	size = ft_strlen(str);
	ten = "";
	if (size == 1)
		unit = ft_unit(str);
	else if (size == 2)
	{
		if (str[0] == '1')
			unit = ft_find(str);
		else
		{
			temp_ten = (get_temp_ten(str[0]));
			ten = ft_find(temp_ten);
			free(temp_ten);
			unit = ft_find(&str[1]);
		}
	}
	else
		unit = "";
	return (make_tens_res(ten, unit));
}

/*char	*ft_hundred(char *str);

// Test hundred + tens
int	main(int argc, char **argv)
{
	char	*res;
	char	*hundred;
	char	*temp;
	char	*tens;

	if (argc >= 2)
	{
		temp = malloc(sizeof(char) * 2);
		temp[0] = argv[1][0];
		temp[1] = '\0';
		hundred = ft_hundred(temp);
		free(temp);

		temp = malloc(sizeof(char) * 3);
		temp[0] = argv[1][1];
		temp[1] = argv[1][2];
		temp[2] = '\0';
		tens = ft_tens(temp);
		free(temp);

		res = malloc(sizeof(char) * (ft_strlen(hundred) + ft_strlen(tens) + 2));
		res[0] = '\0';
		str_append(res, hundred);
		free(hundred);
		str_append(res, " ");
		str_append(res, tens);
		free(tens);
		ft_putstr(res);
		ft_putstr("\n");
		free(res);
	}
}*/
