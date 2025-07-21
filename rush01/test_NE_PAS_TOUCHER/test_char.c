/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:56:01 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 23:14:49 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strlen(char *str);

char	*rm_spaces(char *c)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			dest[j] = c[i];
			j++;
		}
		i++;
	}
	return (dest);
}

int	test_argv(char *c)
{
	char	*dest;
	int		i;
	
	while (c[i])
	{
		if(c[i] == '-')
		{
			write(1, "error\n", 1);
			return 0;
		}
		i++;
	}
	*dest = rm_spaces(c);
	if ((ft_strlen(dest) / 2) != 0)
	{
		write(1, "error\n", 6);
		return 0;
	}
	return 1;
}
