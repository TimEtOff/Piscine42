/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:49:17 by cobussie          #+#    #+#             */
/*   Updated: 2025/07/19 14:14:38 by cobussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define SIZE 4
#include <unistd.h>
void ft_putchar(char c);

void draw_grid(int grid[SIZE+2][SIZE+2]);

int is_possible()
{
	return 0;
}

/*
void recursive_check(int grid[SIZE][SIZE], int size,int current_x,int current_y,int check_value)
{
	if (current_y == size)
		return 1;
	if (check_value > )
	if (is_possible(current_x,current_y,check_value))
		if (current_x == size -1 )
			recursive_check(grid,size,0,current_y+1,check_value);
		else 
			recursive_check(grid,size,current_x + 1, current_y,check_value);
	else
		recursive_check(grid,size,current_x,current_y,check_value + 1);

	}
	*/


int main()
{
	int grid[SIZE+2][SIZE+2];
	int current_x;
	int current_y;
	current_x = 1;
	current_y = 1;
	while (current_x<=SIZE)
	{
		while(current_y<=SIZE)
		{
			grid[current_x][current_y] = 0;
			current_y++;
		}
		current_y = 1;
		current_x++;
	}
	draw_grid(grid);
}
