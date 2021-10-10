/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:13:37 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/10 19:15:07 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_line_counter(char *ref)
{
	int		useful[3];
	int		l;
	char	d;

	l = 0;
	useful[2] = 0;
	useful[1] = 1;
	useful[0] = open(ref, O_RDONLY);
	while (useful[1] == 1)
	{
		useful[1] = read(useful[0], &d, 1);
		if (d == '\n')
			l++;
	}
	close(useful[0]);
	return (l);
}

void	ft_destroy(char **matrix, char *ref)
{
	int	i;
	int	l;

	i = 0;
	l = ft_line_counter(ref);
	while (i < l)
	{
		free((void *) matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free((void **) matrix);
	matrix = NULL;
}
