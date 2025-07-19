/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:04:51 by cobussie          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:52 by cobussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>


int is_valid(int row, int col, int val)
{
	int i;

	i = 0;
	while ( i <= get_size())
	{
		if (i != col)
		{
			if (get_val(row,i) == val)
				return 0;
		}
		if (i != row)
			if (get_val(i,col) == val)
				return 0;
	}
	




	return 1;
}

int check(int row,int col)
{
	int value;
	int size;

	size = get_size();
	value =1;
	if (row == size)
		return 1;
	if (col == size)
		return check( row + 1, 0);
	if (get_val(row,col) != 0)
		return check(row, col + 1);
	while (value <= size)
	{
		if (is_valid(row,col, value))
		{
			set_val(row , col , value);
			if (check(row,col+1))
				return 1;
			set_val(row , col , value);
		
		}
		value++;
	}
	return 0;
	}