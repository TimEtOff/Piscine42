/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_legal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:51:44 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/20 16:23:43 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	get_size(void);
int	get_val(int i, int j);

int	row_legal(int row)
{
	int	j;
	int	j_check;

	j = 1;
	j_check = 2;
	while (j < get_size())
	{
		while (j_check < get_size())
		{
			if (j != j_check && get_val(row, j) == get_val(row, j_check))
				return (0);
			j_check++;
		}
		j_check = 1;
		j++;
	}
	return (1);
}

int	col_legal(int col)
{
	int	i;
	int	i_check;

	i = 1;
	i_check = 2;
	while (i < get_size())
	{
		while (i_check < get_size())
		{
			if (i != i_check && get_val(i, col) == get_val(i_check, col))
				return (0);
			i_check++;
		}
		i_check = 1;
		i++;
	}
	return (1);
}
