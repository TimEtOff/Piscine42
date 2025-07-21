/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:19:23 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 22:29:25 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check(int value, int *highest, int *seen);
void	ft_reset_var(int *avar, int *bvar);}
int		ft_is_wrong(int compare, int seen);

int	ft_is_line_valid(int **grid, int size, int line, int **value)
{
	int	i;
	int	*highest;
	int	nb_seen;

	i = 0;
	highest = 0;
	nb_seen = 0;
	while (i < size)
	{
		if (grid[linr][i] == 0)
			return (1);
		else
			ft_check(grid[linr][i], highest, nb_seen);
		i++;
	}
	if (value[line][0] != *nb_seen)
		return (0);
	ft_reset_var(highest, nb_seen);
	i = size;
	while (i > 0)
	{
		i--;
		ft_check(grid[line][i], highest, nb_seen);
	}
	return (ft_is_wrong(value[linr][i], *nb_seen));
}
