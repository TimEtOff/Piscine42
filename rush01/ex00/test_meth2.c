/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_meth2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:51:36 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/20 16:21:37 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	set_val(int i, int j, int val);
int		get_val(int i, int j);
int		get_size(void);
void	draw_grid(void);
void	ft_putchar(char c);
void	ft_putnbr(char c);
int		row_legal(int row);
int		col_legal(int col);
int		row_valid_from_left(int i);
int		row_valid_from_right(int i);
int		col_valid_from_top(int j);
int		col_valid_from_bot(int j);

int	init_grid_values(void)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= get_size())
	{
		while (j <= get_size())
		{
			set_val(i, j, j);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	move_horizontal(int i)
{
	int	j;
	int	temp;

	j = get_size();
	temp = get_val(i, j);
	while (j > 1)
	{
		set_val(i, j, get_val(i, j - 1));
		j--;
	}
	set_val(i, j, temp);
	return (0);
}

int	move_vertical(int j)
{
	int	i;
	int	temp;

	i = get_size();
	temp = get_val(i, j);
	while (i > 1)
	{
		set_val(i, j, get_val(i - 1, j));
		i--;
	}
	set_val(i, j, temp);
	return (0);
}

int	switch_row(int i)
{
	/*int	j;

	j = 1;
	while (j <= get_size())
	{
		set_val(i, j, get_size() + 1 - j);
		j++;
	}*/
	int	temp;

	temp = get_val(i, 1);
	set_val(i, 1, get_val(i, get_size()));
	set_val(i, get_size(), temp);
	return (0);
}

int	resolve(void)
{
	int	i;
	int	j;
	int	times;

	i = 1;
	j = 1;
	times = 0;
	while (i <= get_size())
	{
		while (!(row_valid_from_left(i) && row_valid_from_right(i)))
		{
			while (times <= 5 && !(row_valid_from_left(i) && row_valid_from_right(i)))
			{
				move_horizontal(i);
				/*ft_putnbr(i);
				ft_putchar(',');
				ft_putnbr(j);
				ft_putchar('\n');
				draw_grid();
				ft_putchar('\n');*/
				times++;
			}
			switch_row(i);
			times = 0;
		}
		/*ft_putnbr(i);
		ft_putchar(',');
		ft_putnbr(j);
		ft_putchar('\n');
		draw_grid();
		ft_putchar('\n');*/
		/*while (!(row_valid_from_right(i)))
		{
			move_vertical(get_size());
			ft_putnbr(i);
			ft_putchar(',');
			ft_putnbr(j);
			ft_putchar('\n');
			draw_grid();
			ft_putchar('\n');
		}*/
		i++;
		times = 0;
	}
	return (0);
}
