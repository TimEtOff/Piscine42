/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:16:37 by tgonthie          #+#    #+#             */
/*   Updated: 2025/07/20 20:43:11 by tgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(int **ptr)
{
	int	cpt;

	cpt = 0;
	while (ptr[0][cpt] != NULL)
	{
		cpt++;
	}
	return (cpt + 1);
}

int	get_val(int **ptr, int row, int col)
{
	return (ptr[row][col]);
}

void	set_val(int **ptr, int row, int col,int val)
{
	ptr[row][col] = val;
}
