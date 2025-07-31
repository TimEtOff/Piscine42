/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yriffard <yriffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:11:07 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/30 20:07:08 by yriffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_map.h"

// ft_utils.c
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	str_append(char *str, char *append);
char	*truncate_str(char *src, int start, int end);

// ft_utlis2.c
int		ft_min(int first_int, int second_int, int third_int);
char	*ft_strdup(char *src);
int		ft_str_is_printable(char *str);
void	ft_putnbr(int nb);

// ft_array_utils.c
int		ft_arraylen(void **array);
char	**truncate_str_array(char **str, int start, int end);
void	ft_putstr_array(char **array, char *sep);

// ft_split.c
char	**ft_split(char *str, char *charset);

// ft_atoi.c
int		ft_atoi(char *str);

// map_file_reading.c
char	*read_user_input(void);
char	*ft_map_to_str(const char *filename);

// map_checking.c
int		map_convert_to_int(t_map *map);
int		map_checking(t_map *map);

// ft_parse_map.c
int		first_line(t_map *res, char *line);
t_map	*ft_parse_map(t_map *res, char *str_map);

// map_filling_with_bsq.c
void	map_modifying(t_map *map);

// ft_strjoin.c
char	*ft_strjoin(int size, char **strs, char *sep);

#endif
