/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:58:08 by hmorales          #+#    #+#             */
/*   Updated: 2021/09/30 11:30:49 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char t[5]);

void	ft_print_comb2(void)
{
	char	a[5];

	a[0] = '0';
	a[1] = '0';
	a[2] = ' ';
	while (a[0] <= '9')
	{
		while (a[1] <= '9')
		{	
			a[3] = a[0];
			a[4] = a[1] + 1;
			while (a[3] <= '9')
			{
				while (a[4] <= '9')
				{
					print(a);
					a[4]++;
				}	
				a[3]++, a[4] = '0';
			}
			a[1]++;
		}
		a[0]++, a[1] = '0';
	}				
}

void	print(char t[5])
{
	char	coma_espacio[2];

	coma_espacio[0] = ',';
	coma_espacio[1] = ' ';
	write(1, &t[0], 1);
	write(1, &t[1], 1);
	write(1, &t[2], 1);
	write(1, &t[3], 1);
	write(1, &t[4], 1);
	if (!(t[0] == '9' && t[1] == '8' && t[3] == '9' && t[4] == '9'))
		write(1, &coma_espacio, 2);
}
