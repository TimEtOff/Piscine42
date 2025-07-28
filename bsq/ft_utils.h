/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:11:07 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/28 15:05:30 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>
# include "ft_map.h"

// ft_utils.c
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	str_append(char *str, char *append);
int		ft_strcmp(char *s1, char *s2);
char	*truncate_str(char *str, int start, int end);

// ft_utlis2.c
int	ft_min(int first_int, int second_int, int third_int);

// ft_array_utils.c
int		ft_str_arraylen(char **array);
char	**truncate_str_array(char **str, int start, int end);

// ft_split.c
char	**ft_split(char *str, char *charset);

// ft_atoi.c
int		ft_atoi(char *str);

// map_file_reading.c
char    *ft_map_to_str(const char *filename);

// map_checking.c
void    map_convert_to_int(t_map *map);
void    map_cheching(t_map *map);

// ft_parse_map.c
int     first_line(t_map *res, char *line);
t_map   *ft_parse_map(t_map *res, char *str_map);

#endif
