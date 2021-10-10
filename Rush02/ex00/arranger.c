/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arranger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:17:43 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/10 23:31:46 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_destroy(char **matrix, char *ref);

char	**arranger(char **matrix, int row, int col, char *ref)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	matrix = (char **) malloc(row * sizeof(char *));
	while (i < row)
	{
		matrix[i] = (char *) malloc(col * sizeof(char));
		i++;
	}
	i = 0;
	return (matrix);
	ft_destroy(matrix, ref);
}

char	**ft_filler(char **matrix, char *ref)
{
	char	d;
	int		useful[4];

	useful[0] = open(ref, O_RDONLY);
	useful[1] = 1;
	useful[2] = 0;
	useful[3] = 0;
	while (useful[1] == 1)
	{
		useful[1] = read(useful[0], &d, 1);
		if (d == '\n')
		{
			matrix[useful[2]][useful[3]] = '\0';
			useful[3] = 0;
			useful[2]++;
		}
		else
		{
			matrix[useful[2]][useful[3]] = d;
			useful[3]++;
		}
	}
	close(useful[0]);
	return (matrix);
}

char	**ft_sizer(char **matrix, char *ref)
{
	int		useful[5];
	char	d;

	useful[4] = 0;
	useful[3] = 0;
	useful[2] = 0;
	useful[1] = 1;
	useful[0] = open(ref, O_RDONLY);
	while (useful[1] == 1)
	{
		useful[1] = read(useful[0], &d, 1);
		useful[2]++;
		if (d == '\n')
		{
			useful[3]++;
			if (useful[2] > useful[4])
				useful[4] = useful[2];
			useful[2] = 0;
		}
	}
	matrix = arranger(matrix, useful[3], useful[4], ref);
	close(useful[0]);
	matrix = ft_filler(matrix, ref);
	return (matrix);
}
