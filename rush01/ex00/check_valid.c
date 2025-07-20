/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 04:43:03 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 07:33:17 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(void);
int	get_val(int i, int j);

void	test(int *current_val, int *current_max, int *count, int *count_0)
{
	if (current_val > current_max)
	{
		current_max = current_val;
		count++;
	}
	else if (current_val == 0)
		count_0++;
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
	if (get_val(row, 0) - count_0 != count)
		return (0);
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
	if (get_val(row, get_size() + 1) - count_0 != count)
		return (0);
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
	if (get_val(0, col) - count_0 != count)
		return (0);
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
	if (get_val(get_size() + 1, col) - count_0 != count)
		return (0);
	return (1);
}
