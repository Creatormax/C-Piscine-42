/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r02_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:48:30 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/10 23:08:39 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	**ft_sizer(char **matrix, char *ref);
void	ft_destroy(char **matrix, char *ref);
void	ft_get_number(char *str, char **matrix);

void	ft_cleaner(char *str)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while ((str[i] <= '\r' && str[i] >= '\t') || str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{	
		if (str[i] == '-' || str[i] == ',' || str[i] == '.')
		{
			write(1, "Error: Program only accepts postive integer numbers", 43);
			exit (1);
		}
		else if (str[i] < '0' || str[i] > '9')
			break ;
		str[a] = str[i];
		i++;
		a++;
	}
	str[a] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	rush02_w_ref(char *str, char *ref)
{
	int		l;
	char	**dict;

	dict = NULL;
	ft_cleaner(str);
	l = ft_strlen(str);
	dict = ft_sizer(dict, ref);
	ft_get_number(str, dict);
	ft_destroy(dict, ref);
}

void	rush02_wout_ref(char *str)
{
	int		l;
	char	**dict;
	char	*ref;

	dict = NULL;
	ref = "numbers.dict";
	ft_cleaner(str);
	l = ft_strlen(str);
	dict = ft_sizer(dict, ref);
	ft_get_number(str, dict);
	ft_destroy(dict, ref);
}
