/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:04:06 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/10 22:41:24 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_test_array(char *str, char **matrix)
{
	int		j;
	int		k;
	char	*ptr;

	j = 0;
	while (j < 42)
	{
		ptr = strstr(matrix[j], str);
		if (ptr && *ptr == matrix[j][0])
		{
			k = 0;
			while (ptr[k] != '\0')
			{
				if (ptr[k] > 96 && ptr[k] < 123)
					write(1, &ptr[k], 1);
				k++;
			}
			write(1, " ", 1);
			return ;
		}
		j++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] - s2[i] > 0)
		return (1);
	else if (s1[i] - s2[i] < 0)
		return (-1);
	else
		return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i ++;
	}
	return (dest);
}
