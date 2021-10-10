/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:01:00 by gmaldona          #+#    #+#             */
/*   Updated: 2021/10/10 23:13:25 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_test_array(char *str, char **matrix);
int		ft_strlen(char *str);
void	ft_first_pass(char *str, int str_len, char **matrix);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_scale_name(int l, char **matrix);
int		ft_conditions(int scale, char *num_div, char *str, char **matrix);

void	ft_number_modulus(char **matrix, char *str)
{
	char	temp[2];
	char	temp2[3];
	char	temp3[2];
	char	num_div[4];

	ft_strncpy(num_div, str, 3);
	temp[0] = num_div[2];
	temp[1] = '\0';
	temp2[0] = num_div[1];
	temp2[1] = '0';
	temp2[2] = '\0';
	temp3[0] = num_div[0];
	temp3[1] = '\0';
	if (temp3[0] != '0')
	{
		ft_test_array(temp3, matrix);
		ft_test_array("100", matrix);
	}
	if (temp2[0] < '2' && temp2[0] != '0')
		temp2[1] = num_div[2];
	ft_test_array(temp2, matrix);
	if (!(temp[0] == '0') && temp[0] != temp2[1])
		ft_test_array(temp, matrix);
	str += 3;
}

void	ft_second_mod(char **matrix, char *str)
{
	char	temp[2];
	char	num_div[4];

	ft_strncpy(num_div, str, 2);
	temp[0] = num_div[1];
	num_div[1] = '0';
	ft_test_array(num_div, matrix);
	if (!(temp[0] == '0'))
		ft_test_array(temp, matrix);
	str += 2;
}

void	ft_get_number(char *str, char **matrix)
{
	int		str_len;

	str_len = ft_strlen(str);
	if ((str_len < 3 && (ft_strcmp(str, "20") == 0 || \
	str[0] < '2')) || str_len == 1)
		ft_test_array(str, matrix);
	else
		ft_first_pass(str, str_len, matrix);
}

void	ft_first_pass(char *str, int str_len, char **matrix)
{
	int		scale;
	char	num_div[4];
	int		l;

	if (str_len < 3)
		scale = str_len % 3;
	else
		scale = str_len % (3 * (str_len / 3));
	scale = ft_conditions(scale, num_div, str, matrix);
	l = ft_strlen(str);
	l = ft_scale_name(l, matrix);
	while (str[scale] != '\0')
	{
		ft_number_modulus(matrix, &str[scale]);
		if (l > 3)
			l = ft_scale_name(l, matrix);
		scale += 3;
	}
}
