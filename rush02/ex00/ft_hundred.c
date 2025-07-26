/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:03:17 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/26 15:05:03 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_find(char *str);

void	make_hundred_res(char *res, char *unit, char *hundred, int nbr)
{
	str_append(res, unit);
	str_append(res, " ");
	str_append(res, hundred);
	if (nbr > 1)
		str_append(res, "s");
}

char	*ft_hundred(char *str)
{
	char	*res;
	int		nbr;
	char	*unit_str;
	char	*hundred_str;
	int		size;

	nbr = str[0] - '0';
	unit_str = ft_find(str);
	hundred_str = ft_find("100");
	size = ft_strlen(unit_str) + ft_strlen(hundred_str) + 2;
	if (nbr > 1)
		size += 1;
	if (ft_strlen(str) != 1 || nbr == 0)
		size = 1;
	res = malloc(sizeof(char) * size);
	if (res == NULL)
		return (0);
	res[0] = '\0';
	if (ft_strlen(str) == 1 && nbr != 0)
		make_hundred_res(res, unit_str, hundred_str, nbr);
	return (res);
}

// Temp function to test values
/*char	*ft_find(char *str)
{
	if (ft_strcmp(str, "1") == 0)
		return ("one");
	else if (ft_strcmp(str, "2") == 0)
		return ("two");
	else if (ft_strcmp(str, "3") == 0)
		return ("three");
	else if (ft_strcmp(str, "4") == 0)
		return ("four");
	else if (ft_strcmp(str, "5") == 0)
		return ("five");
	else if (ft_strcmp(str, "6") == 0)
		return ("six");
	else if (ft_strcmp(str, "7") == 0)
		return ("seven");
	else if (ft_strcmp(str, "8") == 0)
		return ("eight");
	else if (ft_strcmp(str, "9") == 0)
		return ("nine");
	else if (ft_strcmp(str, "100") == 0)
		return ("hundred");
	else
		return ("");
}

int	main(int argc, char **argv)
{
	char	*res;

	if (argc >= 2)
	{
		res = ft_hundred(argv[1]);
		ft_putstr(res);
		ft_putstr("\n");
		free(res);
	}
}*/
