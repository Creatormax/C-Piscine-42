/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:24:10 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/12 17:07:31 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	a;

	i = 0;
	a = argc - 1;
	if (argc > 1)
	{
		while (a > 0)
		{
			while (argv[a][i] != '\0')
			{
				write(1, &argv[a][i], 1);
				i++;
			}
			write(1, "\n", 1);
			a--;
			i = 0;
		}
	}
}
