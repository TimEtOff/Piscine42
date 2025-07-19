#include <unistd.h>

#define SIZE 4
void ft_putchar(char c)
{
	write(1,&c,1);
}

void draw_grid(int grid[SIZE+2][SIZE+2])
{
	int i;
	int j;
	
	i=1;
	j=1;
	while (i<=SIZE)
	{
		while(j<=SIZE)
		{
			ft_putchar(grid[i][j] + '0');
			if (j != SIZE)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j=1;
		i++;
	}
}