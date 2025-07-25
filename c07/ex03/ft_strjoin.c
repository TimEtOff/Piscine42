/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:04:45 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/25 10:41:38 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_size(int size, char **strs, char *sep)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		res += ft_strlen(strs[i]);
		i++;
	}
	res += ft_strlen(sep) * (size - 1);
	if (size <= 0)
		res = 1;
	res++;
	return (res);
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		size_m;

	size_m = get_size(size, strs, sep);
	res = malloc(sizeof(char) * size_m);
	if (res == NULL)
		return (0);
	res[0] = '\0';
	i = 0;
	if (size > 0)
	{
		while (i < size)
		{
			str_append(res, strs[i]);
			if (i < size - 1)
				str_append(res, sep);
			i++;
		}
		res[size_m - 1] = '\0';
	}
	return (res);
}

/*int	main(void)
{
	char	**strs = (char *[]){"Hello", "World", "!", "Test", "One"};
	char	*res;

	res = ft_strjoin(5, strs, ";");
	__builtin_printf("%s\n", res);
	free(res);
	return (0);
}*/
