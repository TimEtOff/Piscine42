/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:11:07 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/27 18:04:44 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>

int		ft_strlen(char *str);

void	ft_putstr(char *str);

void	str_append(char *str, char *append);

int		ft_strcmp(char *s1, char *s2);

#endif
