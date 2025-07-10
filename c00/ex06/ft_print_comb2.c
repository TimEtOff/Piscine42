#include <unistd.h>

void	ft_print_comb2(void)
{
	char	numbers1[2];
	char	numbers2[2];

	numbers1[0] = '0';
	numbers1[1] = '0';
	numbers2[0] = '0';
	numbers2[1] = '1';

	while (numbers1[0] <= '9')
	{
		while (numbers1[1] <= '9')
		{
			while (numbers2[0] <= '9')
			{
				while (numbers2[1] <= '9')
				{
					if (numbers1[0] + numbers1[1] != numbers2[0] + numbers2[1])
					{
						write(1, numbers1, 2);
						write(1, " ", 1);
						write(1, numbers2, 2);
						write(1, ", ", 2);
					}
					numbers2[1] ++;
				}
				numbers2[1] = '0';
				numbers2[0] ++;
			}
			numbers2[0] = '0';
			numbers1[1] ++;
		}
		numbers1[1] = '0';
		numbers1[0] ++;
	}

}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
