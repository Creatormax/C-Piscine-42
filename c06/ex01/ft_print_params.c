/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:58:40 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/12 17:07:19 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	a;

	i = 0;
	a = 1;
	while (a < argc)
	{
		while (argv[a][i] != '\0')
		{
			write(1, &argv[a][i], 1);
			i++;
		}
		write(1, "\n", 1);
		a++;
		i = 0;
	}
}
