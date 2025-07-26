/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:07:33 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/26 14:08:54 by tgodefro         ###   ########lyon.fr   */
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
