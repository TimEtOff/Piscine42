/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:28:11 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/26 13:59:58 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_in(char c, char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res = 1;
		i++;
	}
	return (res);
}

int	count_words(char *str, char *charset)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 && !is_in(str[i], charset))
			|| (!is_in(str[i], charset)
				&& is_in(str[i - 1], charset)))
			res++;
		i++;
	}
	return (res);
}

/*char	**ft_split(char *str, char *charset)
{
	
}*/

int	main(void)
{
	__builtin_printf("%i\n", count_words("sr ggg  2", " "));
}
