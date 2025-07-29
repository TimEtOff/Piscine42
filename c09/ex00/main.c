/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:47:50 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/29 22:06:11 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	ft_swap(&i, &j);
	ft_putchar(i + '0');
	ft_putchar(j + '0');
	ft_putstr("Str");
	ft_strlen("test");
	ft_putchar(j + '0');
	ft_putchar(ft_strcmp("Hello", "World") + '0');
	return (0);
}
