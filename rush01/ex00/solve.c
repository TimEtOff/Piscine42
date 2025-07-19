
#include <unistd.h>




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