/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:55:33 by mboutte           #+#    #+#             */
/*   Updated: 2025/07/26 20:08:46 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	ft_calc_size(int size, char **strs, char *sep)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	if (size == 0)
		return (1);
	while (++i < size)
		res += ft_strlen(strs[i]);
	return (res + 1 + (ft_strlen(sep) * (size - 1)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		c;
	int		i;
	int		j;

	join = malloc(sizeof(char) * ft_calc_size(size, strs, sep));
	if (!join)
		return (NULL);
	i = -1;
	c = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			join[c++] = strs[i][j];
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j])
				join[c++] = sep[j];
		}
	}
	join[c] = '\0';
	return (join);
}

/*int	main(void)
{
	char s1[] = "mot1";
	char s2[] = "mot2";
	char s3[] = "mot3";
	char *s_global[3];
	char	sep[] = "/sep\\";
	int	size = 3;

	s_global[0] = s1;
	s_global[1] = s2;
	s_global[2] = s3;
	__builtin_printf("test =%d\n", ft_calc_size(size, s_global, sep));
	__builtin_printf("%s", ft_strjoin(size, s_global, sep));
	return (0);
}*/
