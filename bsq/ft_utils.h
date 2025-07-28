/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:11:07 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/28 12:57:46 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>

// ft_utils.c
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	str_append(char *str, char *append);
int		ft_strcmp(char *s1, char *s2);
char	*truncate_str(char *str, int start, int end);

// ft_array_utils.c
int		ft_str_arraylen(char **array);
char	**truncate_str_array(char **str, int start, int end);

// ft_split.c
char	**ft_split(char *str, char *charset);

// ft_atoi.c
int		ft_atoi(char *str);

#endif
