/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:10:51 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/13 14:01:08 by dbeal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line_top(int x_max, int y_max, int y_actual)
{
	int	increment;
	int	upper_left;
	int	upper_right;
	int	bottom_left;
	int	bottom_right;

	increment = 0;
	while (increment < x_max)
	{
		{
			upper_left = ((increment == 0) && (y_actual == 0));
			upper_right = ((increment == (x_max - 1)) && (y_actual == 0));
			bottom_left = ((increment == 0) && (y_actual == (y_max - 1)));
			bottom_right = (increment == (x_max - 1));
			bottom_right = bottom_right && (y_actual == (y_max - 1));
		}
		if (upper_left || upper_right || bottom_left || bottom_right)
			ft_putchar('o');
		else
			ft_putchar('-');
		increment++;
	}
}

void	ft_line(int x)
{
	int	increment;

	increment = 0;
	while (increment < x)
	{
		if ((increment == 0) || (increment == (x - 1)))
			ft_putchar('|');
		else
			ft_putchar(' ');
		increment++;
	}
}

void	rush(int x, int y)
{
	int	incr_y;

	incr_y = 0;
	while (incr_y < y)
	{
		if (incr_y == 0 || incr_y == (y - 1))
			ft_line_top(x, y, incr_y);
		else
			ft_line(x);
		ft_putchar('\n');
		incr_y++;
	}
}
