/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:07:33 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/28 13:08:38 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	str_append(char *str, char *append)
{
	int	i;
	int	str_len;
	int	app_len;

	str_len = ft_strlen(str);
	app_len = ft_strlen(append);
	i = 0;
	while (i < app_len)
	{
		str[str_len + i] = append[i];
		i++;
	}
	str[str_len + i] = '\0';
}

int	ft_strcmp(char *s1, char *s2)
{
	int	res;

	res = 0;
	while (res == 0 || (*s1 == '\0' && *s2 == '\0'))
	{
		if (*s1 != *s2)
			res = (int) *s1 - (int) *s2;
		else if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (res);
}

char	*truncate_str(char *str, int start, int end)
{
	char	*new_str;
	int		i;

	if (end == -1)
		end = ft_strlen(str);
	new_str = malloc(sizeof(char) * (end - start));
	i = 0;
	while (i < (end - start))
	{
		new_str[i] = str[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
