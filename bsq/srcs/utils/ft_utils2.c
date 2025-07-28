/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yriffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:18:24 by yriffard          #+#    #+#             */
/*   Updated: 2025/07/28 13:18:33 by yriffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int first_int, int second_int, int third_int)

{
	int	res;

	if (first_int < second_int)
		res = first_int;
	else 
		res = second_int;
		
	if (res > third_int)
		res = third_int;
	return (res);
}
