/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:18:16 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/10 23:31:37 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush02_wout_ref(char *str);
void	rush02_w_ref(char *str, char *ref);

int	main(int argc, char **argv)
{
	char	*str;
	char	*ref;

	if (argc != 3 && argc != 2)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	else if (argc == 3)
	{
		ref = argv[1];
		str = argv[2];
		rush02_w_ref(str, ref);
	}
	else if (argc == 2)
	{
		str = argv[1];
		rush02_wout_ref(str);
	}
}
