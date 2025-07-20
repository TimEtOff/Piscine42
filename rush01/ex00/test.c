#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	occ_char_in_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
#include <unistd.h>

int		get_size(void);
void	set_val(int i, int j, int val);
void	draw_grid(void);
int		get_val(int i, int j);
int		row_valid_from_left(int row);
int		row_valid_from_right(int row);
int		col_valid_from_top(int col);
int		col_valid_from_bot(int col);

int	is_valid(int row, int col, int val)
{
	int	i;

	i = 1;
	while (i <= get_size())
	{
		if (i != col)
		{
			if (get_val(row, i) == val)
				return (0);
		}
		if (i != row)
		{
			if (get_val(i, col) == val)
				return (0);
		}
		i++;
	}
	if (!col_valid_from_bot(col) || !col_valid_from_top(col)
		|| !row_valid_from_right(row) || !row_valid_from_left(row))
	{
		return (0);
	}
	return (1);
}

int	check(int row, int col)
{
	int	value;
	int	size;

	size = get_size();
	value = 1;
	if (row > size)
		return (1);
	if (col > size)
	{
		return (check(row + 1, 1));
	}
	/*
	if (get_val(row, col) != 0)
		return (check(row, col + 1));*/
	while (value <= size)
	{
		set_val(row, col, value);
		if (is_valid(row, col, value) == 1)
		{
			//draw_grid();
			//ft_putchar('\n');
			if (check(row, col + 1) == 1)
			{
				
				return (1);
			}
			
		}
		set_val(row, col, 0);
		value++;
	}

	return (0);
}
#include <unistd.h>
#define SIZE 4

void	ft_putchar(char c);
void	free_grid(void);
void	draw_grid(void);
void	set_val(int i, int j, int val);
int             init_grid(void);
int		get_val(int i, int j);
int		occ_char_in_str(char *str, char c);
int		ft_strlen(char *str);
int		check(int row, int col);

int	get_size(void)
{
	return (SIZE);
}

int	put_in_grid(char *input, int index, int i, int j)
{
	int	max;

	max = index + (get_size() * 2);
	while (index < max)
	{
		if (('1' <= input[index]) && (input[index] <= get_size() + '0'))
			set_val(i, j, input[index] - '0');
		if (!(j == 0 || j == get_size() + 1))
			j++;
		else
			i++;
		index++;
		if (input[index] == ' ')
			index++;
	}
	return (index);
}

int	input_errors(char *input)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (ft_strlen(input) != (get_size() * get_size() * 2 - 1))
		res += 1;
	else
	{
		while (input[i] != '\0')
		{
			if (i % 2 == 0)
			{
				if (!(('1' <= input[i]) && (input[i] <= get_size() + '0')))
				{
					res += 1;
				}
			}
			else if (input[i] != ' ')
				res += 1;
			i++;
		}
	}
	return (res);
}

int	init_input(char *input)
{
	int	res;
	int	index;

	res = 0;
	index = 0;
	res += input_errors(input);
	if (res == 0)
	{
		index = put_in_grid(input, index, 0, 1);
		index = put_in_grid(input, index, get_size() + 1, 1);
		index = put_in_grid(input, index, 1, 0);
		index = put_in_grid(input, index, 1, get_size() + 1);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	res;

	res = 0;
	res = init_grid();
	if (argc <= 2)
	{
		res += init_input("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
			//draw_grid();
		if (res == 0)
		{
			if (check(1, 1) == 1)
				draw_grid();
		}
	}
	else
		res = 1;
	free_grid();
	if (res != 0)
		write(1, "Error\n", 6);
	return (res);
}
#include <unistd.h>
#include <stdlib.h>

int		get_size(void);
void	ft_putchar(char c);

static int	**g_grid;

void	set_val(int i, int j, int val)
{
	g_grid[i][j] = val;
}

int	get_val(int i, int j)
{
	return (g_grid[i][j]);
}

int	init_grid(void)
{
	int	i;

	i = 0;
	g_grid = malloc(sizeof(int *[get_size() + 2]));
	if (g_grid == NULL)
		return (EXIT_FAILURE);
	while (i < get_size() + 2)
	{
		g_grid[i] = malloc(sizeof(int [get_size() + 2]));
		if (g_grid == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

void	free_grid(void)
{
	int	i;

	i = 0;
	while (i < get_size() + 2)
	{
		free(g_grid[i]);
		i++;
	}
	free(g_grid);
}

void	draw_grid(void)
{
	int	row;
	int	col;

	row = 1;
	col = 1;
	while (row <= get_size())
	{
		while (col <= get_size())
		{
			ft_putchar(g_grid[row][col] + '0');
			if (col != get_size()+1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		col = 1;
		row++;
	}
}
int	get_size(void);
int	get_val(int i, int j);

void	test(int *current_val, int *current_max, int *count, int *count_0)
{
	if (*current_val > *current_max)
	{
		*current_max = *current_val;
		(*count)++;
	}
	else if (*current_val == 0)
		(*count_0)++;
}

int	row_valid_from_left(int row)
{
	int	i;
	int	current_max;
	int	current_val;
	int	count;
	int	count_0;

	i = 1;
	count = 0;
	count_0 = 0;
	current_max = 0;
	current_val = 0;
	while (i <= get_size())
	{
		current_val = get_val(row, i);
		test(&current_val, &current_max, &count, &count_0);
		i++;
	}
	int needed = get_val(row, 0);
	if (count_0 != 0 && needed <= count)
		return (1);
	if (needed == count)
		return (1);
	return (1);
}

/*
	int row_from_left;
	int row_from_right;
	row_from_left = get_val(row,0);
	row_from_right = get_val(row,get_size()+1);
	*/
int	row_valid_from_right(int row)
{
	int	i;
	int	current_max;
	int	current_val;
	int	count;
	int	count_0;

	i = get_size();
	count = 0;
	count_0 = 0;
	current_max = 0;
	current_val = 0;
	while (i >= 1)
	{
		current_val = get_val(row, i);
		test(&current_val, &current_max, &count, &count_0);
		i--;
	}
	int needed = get_val(row, get_size() + 1);
	if (count_0 != 0 && needed <= count)
		return (1);
	if (needed == count)
		return (1);
	return (1);
}

int	col_valid_from_top(int col)
{
	int	i;
	int	current_max;
	int	current_val;
	int	count;
	int	count_0;

	i = 1;
	count = 0;
	count_0 = 0;
	current_max = 0;
	current_val = 0;
	while (i <= get_size())
	{
		current_val = get_val(i, col);
		test(&current_val, &current_max, &count, &count_0);
		i++;
	}
	int needed = get_val(0, col);
	if (count_0 != 0 && needed <= count)
		return (1);
	if (needed == count)
		return (1);
	return (1);
}

int	col_valid_from_bot(int col)
{
	int	i;
	int	current_max;
	int	current_val;
	int	count;
	int	count_0;

	i = get_size();
	count = 0;
	count_0 = 0;
	current_max = 0;
	current_val = 0;
	while (i >= 1)
	{
		current_val = get_val(i, col);
		test(&current_val, &current_max, &count, &count_0);
		i--;
	}
	int needed = get_val(get_size() + 1, col);
	if (count_0 != 0 && needed <= count)
		return (1);
	if (needed == count)
		return (1);
	return (0);
}
