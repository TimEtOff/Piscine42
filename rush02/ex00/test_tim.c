/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:50:48 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/26 20:50:27 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_find(char *str, char *path);

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

int	check_find(char *str, char *find, int i_check)
{
	int i_0;

	if (ft_strlen(find) > 0)
	{
		ft_putstr(find);
		ft_putstr(" ");
		free(find);
		i_0 = i_check;
		while (i_0 < ft_strlen(str))
		{
			str[i_0] = '0';
			i_0++;
		}
		return (1);
	}
	return (0);
}

int	all_zero(char *str)
{
	int	res;

	res = 1;
	while (*str)
	{
		if (*str != '0')
			res = 0;
		str++;
	}
	return (res);
}

void	ft_rush02(char *str, char *path)
{
	int		i;
	int		i_check;
	int		size;
	char	*temp;
	char	*find;

	size = ft_strlen(str);
	i = size - 1;
	i_check = 0;
	if (all_zero(str))
	{
		find = ft_find("0", path);
		if (check_find(str, find, i_check))
			i = -1;
	}
	while (i >= 0)
	{
		while (i_check <= i && !all_zero(str))
		{
			temp = truncate_str(str, i_check, -1);
			find = ft_find(temp, path);
			free(temp);
			if (check_find(str, find, i_check))
				i_check = i + 1;
			else if (i_check == i)
			{
				temp = truncate_str(str, i_check, i_check + 1);
				find = ft_find(temp, path);
				free(temp);
				if (check_find(str, find, i_check))
				{
					if (i_check != size - 1)
					{
						str[i_check] = '1';
						temp = truncate_str(str, i_check, -1);
						find = ft_find(temp, path);
						free(temp);
						if (check_find(str, find, i_check))
							ft_putstr("s ");
					}
					i_check = i + 1;
				}
			}
			i_check++;
		}
		i_check = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	char *path;

	if (argc >= 2)
	{
		path = "numbers.dict";
		if (argc >= 3)
			path = argv[2];
		ft_rush02(argv[1], path);
		ft_putstr("\n");
	}
	return (0);
}
