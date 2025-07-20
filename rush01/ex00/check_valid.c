/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 04:43:03 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 15:52:23 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	get_size(void);
int	get_val(int i, int j);
int	row_legal(int row);
int	col_legal(int col);

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

int	row_valid_from_left(int i)
{
	int	wanted;
	int	count;
	int	last;
	int	j;

	wanted = get_val(i, 0);
	last = 0;
	count = 0;
	j = 1;
	while (get_val(i, j) <= get_size())
	{
		if (last < get_val(i, j))
		{
			last = get_val(i, j);
			count++;
		}
		j++;
	}
	return (count == wanted && row_legal(i));
}

int	row_valid_from_right(int i)
{
	int	wanted;
	int	count;
	int	last;
	int	j;

	wanted = get_val(i, get_size() + 1);
	last = 0;
	count = 0;
	j = get_size();
	while (get_val(i, j) <= get_size())
	{
		if (get_val(i, j) > last)
		{
			last = get_val(i, j);
			count++;
		}
		j--;
	}
	return ((count == wanted) && row_legal(i));
}

int	col_valid_from_top(int j)
{
	int	wanted;
	int	count;
	int	last;
	int	i;

	wanted = get_val(j, 0);
	last = 0;
	count = 0;
	i = 1;
	while (get_val(i, j) <= get_size())
	{
		if (get_val(i, j) > last)
		{
			last = get_val(i, j);
			count++;
		}
		i++;
	}
	return ((count == wanted) && col_legal(j));
}

int	col_valid_from_bot(int j)
{
	int	wanted;
	int	count;
	int	last;
	int	i;

	wanted = get_val(j, get_size() + 1);
	last = 0;
	count = 0;
	i = get_size();
	while (get_val(i, j) <= get_size())
	{
		if (get_val(i, j) > last)
		{
			last = get_val(i, j);
			count++;
		}
		i--;
	}
	return ((count == wanted) && col_legal(j));
}
