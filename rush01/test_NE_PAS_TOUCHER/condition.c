/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:54:22 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 23:26:40 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     get_size(int **ptr);
void	ft_check(int value, int *highest, int *seen);
void	ft_reset_var(int *avar, int *bvar);
int		ft_is_wrong(int compare, int seen);
int		ft_is_line_valid(int **grid, int size, int line, int **value);
int		ft_is_column_valid(int **grid, int size, int column, int **value);

//check if the value is the highest yet & if so store value & incr num of seen
void	ft_check(int value, int *highest, int *seen)
{
	if (value > *highest)
	{
		*highest = value;
		*seen = *seen + 1;
	}
}

//set all var for check back to 0
void	ft_reset_var(int *avar, int *bvar)
{
	*avar = 0;
	*bvar = 0;
}

//check if the value seen are the value asked
int	ft_is_wrong(int compare, int seen)
{
	if (compare != seen)
		return (0);
	else
		return (1);
}

//main working ft for lines
int	ft_is_line_valid(int **grid, int size, int line, int **value)
{
	int	i;
	int	*highest;
	int	*nb_seen;

	i = 0;
	highest = 0;
	nb_seen = 0;
	while (i < size)
	{
		if (grid[line][i] == 0)
			return (1);
		else
			ft_check(grid[0][line], highest, nb_seen);
		i++;
	}
	if (value[0][line] != *nb_seen)
		return (0);
	ft_reset_var(highest, nb_seen);
	i = size;
	while (i > 0)
	{
		i--;
		ft_check(grid[line][i], highest, nb_seen);
	}
	return (ft_is_wrong(value[1][line], *nb_seen));
}

int	is_valid_line(int nb, int **grid, int y)
{
	int	i;

	i = 0;
	while (i < get_size())
	{
		if (grid[y][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_column(int nb, int **grid, int x)
{
	int	i;

	i = 0;
	while (i < get_size())
	{
		if (grid[i][x] == nb)
			return (0);
		i++;
	}
	return (1);
}

//main working ft for columns
int	ft_is_column_valid(int **grid, int size, int column, int **value)
{
	int	i;
	int	*highest;
	int	*nb_seen;

	i = 0;
	highest = 0;
	nb_seen = 0;
	while (*i < size)
	{
		if (grid[i][column] == 0)
			return (1);
		else
			ft_check(grid[i][column], highest, nb_seen);
		i++;
	}
	if (value[2][column] != *nb_seen)
		return (0);
	ft_reset_var(highest, nb_seen);
	i = size;
	while (*i > 0)
	{
		i--;
		ft_check(grid[i][column], highest, nb_seen);
	}
	return (ft_is_wrong(value[3][column], *nb_seen));
}

int	fill_position(int **grid, int position)
{
	int	nb;
	int	valid;

		ft_print_grid(grid);
		printf("\n\n");
	valid = 0;
	if (position >= (get_size()) * (get_size()))
		return (1);
	if (position < 1)
		return (0);
	nb = 0;
	while (++nb <= get_size())
	{
		if (is_valid_line(nb, grid, position / get_size())
			&& is_valid_column(nb, grid, position % get_size()))
		{
			grid[position / get_size()][position % get_size()] = nb;
			valid = fill_position(grid, position + 1);
		}
	}
	if (!valid)
	{
		grid[position / get_size()][position % get_size()] = 0;
		return (0);
	}
	return (1);
}
