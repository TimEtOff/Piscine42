/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:03:21 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 10:30:21 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

struct s_map
{
	unsigned long	lines_nb;
	unsigned char	empty_char;
	unsigned char	obstacle_char;
	unsigned char	full_char;
	char			**map;
};

typedef struct s_map	t_map;
