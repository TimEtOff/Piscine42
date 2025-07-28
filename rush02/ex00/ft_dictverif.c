/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictverif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaponte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:33:18 by nlaponte          #+#    #+#             */
/*   Updated: 2025/07/27 23:04:58 by nlaponte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_utils.h"

char	*get_file(char *path);
int		errorcase(int n);
int		zero_to_colon(char *file, int i);
int		colon_to_nullbyte(char *file, int i);

int	ft_dictverif(char *file)
{
	int	i;
	int	j;
	int	i1;
	int	i2;

	i = 0;
	j = 0;
	while (file[j] != '\0')
	{
		zero_to_colon(file, i);
		i1 = zero_to_colon(file, i);
		colon_to_nullbyte(file, i1);
		i2 = colon_to_nullbyte(file, i1);
		j++;
	}
	if (i2 == 0 || i1 == 0)
		return (errorcase(1));
	i++;
	return (0);
}

int	zero_to_colon(char *file, int i)
{
	if (!(file[i] >= '0' && file[i] <= '9'))
		return (errorcase(1));
	while (file[i] != ':')
	{
		if (!(file[i] >= '0' && file[i] <= '9'))
			break ;
		i++;
	}
	while (file[i] != ':')
	{
		if (((file[i] >= 9 && file[i] <= 13) || (file[i] == ' ')))
			i++;
		else
			return (0);
	}
	return (i);
}

int	colon_to_nullbyte(char *file, int i)
{
	i++;
	if (file[i] == '\n')
		return (0);
	while (file[i] != '\n')
	{
		if (!((file[i] >= 9 && file[i] <= 13) || (file[i] == ' ')))
			break ;
		i++;
	}
	while (file[i] != '\n')
	{
		if (file[i] >= ' ' && file[i] <= '~')
			i++;
		else
			return (0);
	}
	return (i);
}

int	errorcase(int n)
{
	write(1, "Dict Error\n", 11);
	return (n);
}

