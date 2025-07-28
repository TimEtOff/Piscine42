/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:36:39 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/28 12:57:30 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**truncate_str_array(char **str, int start, int end)
{
	char	*new_str;
	int		i;

	if (end == -1)
		end = ft_strlen(str);
	new_str = malloc(sizeof(char *) * (end - start));
	i = 0;
	while (i < (end - start))
	{
		new_str[i] = str[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
