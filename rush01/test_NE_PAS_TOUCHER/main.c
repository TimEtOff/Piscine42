/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:58:23 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 23:14:37 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *rm_spaces(char *c);
int     	test_argv(char *c);
int		**init_grid(int taille);
int		**init_input(char *input, int **ptr);
int     	**init_nul(int **ptr, int taille);
int		ft_is_line_valid(int **grid, int size, int line, int **value);
/**
int	main(int argc, char **argv)
{
	int		*grid;
	char	*nbr;

	if (argc < 2) 
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (test_argv(argv[1][0]) != 1)
		return (0);
	nbr = rm_spaces(argv[1][0]);
	ptr = init_grid((ft_strlen(*nbr) / 4));
	ptr = init_input(nbr, ptr);
	ptr = init_nul(ptr, (ft_strlen(*nbr) / 4));
	if (ft_is_line_valid(ptr, (ft_strlen(*nbr) / 4), 1, 0) == 1)
	{
		write(1, "error\n", 6);
                return (0);
	}
	
}*/
int	main(void)
{
	int	grid[SIZE][SIZE];

	printf("===== init grid =====");
	ft_init_grid(3, grid);
	printf("\n");
	ft_print_grid(grid);
	printf("===== resolve grid =====\n");
	fill_position(grid, 1);
	ft_print_grid(grid);
}
