/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:03:21 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/30 11:49:23 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

struct s_map
{
	unsigned int	nb_row;
	unsigned int	nb_col;

	unsigned int	biggest_row_index;
	unsigned int	biggest_col_index;
	unsigned int	biggest_value;

	unsigned char	empty_char;
	unsigned char	obstacle_char;
	unsigned char	full_char;

	char			**map;
	unsigned int	**values_map;
};

typedef struct s_map	t_map;

#endif
