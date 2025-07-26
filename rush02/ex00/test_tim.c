/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:50:48 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/26 18:33:48 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_find(char *str, char *path);

char	*truncate_str(char *str, int start, int end)
{
	char	*new_str;
	int		i;

	if (end == -1)
		end = ft_strlen(str) - 1;
	new_str = malloc(sizeof(char) * (end - start));
	i = 0;
	while (i < (end - start))
	{
		new_str[i] = str[start + i];
		i++;
	}
	return (new_str);
}

void	ft_rush02(char *str)
{
	int		i;
	int		i_check;
	int		size;
	char	*temp;
	char	*find;
	int		i_0;
	char	path[] = "numbers.dict";

	size = ft_strlen(str);
	i = size - 1;
	i_check = 0;
	while (i >= 0)
	{
		while (i_check <= i)
		{
			temp = truncate_str(str, i_check, -1);
			find = ft_find(temp, path);
			free(temp);
			if (ft_strlen(find) > 0)
			{
				__builtin_printf("%s ", find);
				free(find);
				i_0 = i;
				while (i_0 < size)
				{
					str[i_0] = '0';
					i_0++;
				}
				i--;
				i_check = 0;
			}
			else if (i_check == i)
			{
				temp = truncate_str(str, i_check, i_check + 1);
				find = ft_find(temp, path);
				free(temp);
				if (ft_strlen(find) > 0)
				{
					__builtin_printf("%s ", find);
					free(find);
					i_0 = i;
					while (i_0 < size)
					{
						str[i_0] = '0';
						i_0++;
					}
					i--;
					i_check = 0;
				}
			}
			i_check++;
		}
		__builtin_printf("\n");
		i_check = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		ft_rush02(argv[1]);
	}
	return (0);
}
