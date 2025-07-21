/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:04:35 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 23:20:11 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    ft_putnbr(int nb);
void    ft_putchar(char c);
int		ft_strlen(char *str);
int		get_size(int **ptr);
void		set_val(int **ptr, int row, int col,int val)

int	**init_nul(int **ptr, int taille)
{
	int     res;
        int     i;
        int     j;

        j = 0;
        i = 0;
	while (ptr[taille - 1][taille - 1] != 0)
        {
		if (ptr[i][taille-1] != 0)
		{
			set_val(ptr, j, i, val);
			i++;
		}
		else
			j++;
			i = 0;
	}
}
int	**init_input(char *input, int **ptr)
{
        int     res;
	int	i;
	int	j;

	j = 0;
	i = 0;
	res = (ft_strlen(input) / 4);
	while (input[i] != res)
	{
		ptr[j][0] = input[i];
		i++;
		j++;
	}
	j = 0;
	while (input[i] != 2 * res)
        {
                ptr[j][get_size(ptr) - 1] = input[i];
                i++;
                j++;
        }
	j = 0;
	while (input[i] != 3 * res)
        {
                ptr[0][j] = input[i];
                i++;
                j++;
        }
	j = 0;
	while (input[i] != 4 * res)
        {
                ptr[get_size(ptr) - 1][j] = input[i];
                i++;
                j++;
        }

}

int	**init_grid(int taille)
{
        int     i;
	int	**ptr

        i = 0;
        **ptr = malloc(sizeof(int *[taille]));
        if (**ptr == NULL)
                return (EXIT_FAILURE);
        while (i < get_size(ptr) + 2)
        {
                *ptr = malloc(sizeof(int [taille]));
                if (**ptr == NULL)
                        return (EXIT_FAILURE);
                i++;
        }
        return (*ptr);
}

void    free_grid(int **ptr)
{
        int     i;

        i = 0;
        while (i < get_size(ptr) + 2)
        {
                free(**ptr);
                i++;
        }
        free(*ptr);
}

void    draw_grid(int **ptr)
{
        int     i;
        int     j;

        i = 1;
        j = 1;
        while (i <= get_size(ptr))
        {
                while (j <= get_size(ptr))
                {
                        ft_putnbr(get_val(ptr, i, j));
                        if (j != get_size(ptr))
                                ft_putchar(' ');
                        j++;
                }
                ft_putchar('\n');
                j = 1;
                i++;
        }
}

void	ft_init_grid(int nb, int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = -1;
			j++;
		}
		i++;
	}
	grid[0][0] = nb;
}
