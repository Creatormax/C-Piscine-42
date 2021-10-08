/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:25:57 by hmorales          #+#    #+#             */
/*   Updated: 2021/09/30 15:55:16 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	matrix[5];

	matrix[0] = '0';
	matrix[1] = '1';
	matrix[2] = '2';
	matrix[3] = ',';
	matrix[4] = ' ';
	while (matrix[0] <= '7')
	{
		while (matrix[1] <= '8')
		{
			while (matrix[2] <= '9')
			{
				if (matrix[0] == '7' && matrix[1] == '8' && matrix[2] == '9')
					write(1, &matrix, 3);
				else
					write(1, &matrix, 5);
				matrix[2]++;
			}
			matrix[1]++, matrix[2] = matrix[1] + 1;
		}
		matrix[0]++, matrix[1] = matrix[0] + 1;
		matrix[2] = matrix[0] + 2;
	}	
}
