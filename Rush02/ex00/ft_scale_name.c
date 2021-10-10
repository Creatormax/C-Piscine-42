/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:42:17 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/10 23:17:46 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_test_array(char *str, char **matrix);
void	ft_second_mod(char **matrix, char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_number_modulus(char **matrix, char *str);

int	ft_scale_name(int l, char **matrix)
{
	int		x;
	int		i;
	char	*aux;

	x = 0;
	i = 0;
	if (l >= 4)
		x = ((l - 4) / 3) + 1;
	aux = (char *) malloc(((x * 3) + 2));
	aux[i] = '1';
	i++;
	while (i <= (x * 3))
	{
		aux[i] = '0';
		i++;
	}
	aux[i] = '\0';
	ft_test_array(aux, matrix);
	free ((void *) aux);
	return (l - 3);
}

int	ft_conditions(int scale, char *num_div, char *str, char **matrix)
{
	if (scale == 1)
	{
		ft_strncpy(num_div, str, 1);
		ft_test_array(num_div, matrix);
		scale = 1;
	}	
	else if (scale == 2)
	{
		ft_second_mod(matrix, str);
		scale = 2;
	}
	else if (scale == 0)
	{
		ft_number_modulus(matrix, str);
		scale = 3;
	}
	return (scale);
}
