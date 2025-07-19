/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:49:17 by cobussie          #+#    #+#             */
/*   Updated: 2025/07/19 11:37:48 by cobussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define SIZE 4
#include <unistd.h>

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


void draw_grid(int grid[SIZE+1][SIZE+1])
{
	int i;
	int j;
	i=1;
	j=1;
	char temp;
	while (i<=SIZE)
	{
		while(j<=SIZE)
		{
			temp = grid[i][j] + '0';
			write(1,&temp,1);
			write(1," ",1);
			j++;
		}
		j=1;
		write(1,"\n",1);
		i++;
	}
}
int main()
{
	int grid[SIZE+1][SIZE+1];
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
