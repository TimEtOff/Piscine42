/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgodefro <tgodefro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:50:28 by tgodefro          #+#    #+#             */
/*   Updated: 2025/07/19 12:15:42 by tgodefro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		get_size();
void	set_val(int i, int j, int val);

int	init_input(char *input)
{
	int	res;

	res = 0;

}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (init_input(argv[1]))
			return (1);
		else
			;
	}
	else
		return (1);
}
