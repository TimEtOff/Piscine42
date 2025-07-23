/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:04:45 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/23 18:00:17 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
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
		res = 0;
	return (res);
}

void	add_in_str(char *src, char *append)
{
	int	i;
	int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len + ft_strlen(append))
	{
		src[src_len + i] = append[i];
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * get_size(size, strs, sep));
	i = 0;
	if (size <= 0)
	{
		while (i < size)
		{
			add_in_str(res, strs[i]);
			if (i < size - 1)
				add_in_str(res, sep);
			i++;
		}
	}
	return (res);
}

int	main(void)
{
	char	strs[5][100];

	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "!";
	strs[3] = "Test";
	strs[4] = "One";
	__builtin_printf("%s", ft_strjoin(5)",", );
	return (0);
}
