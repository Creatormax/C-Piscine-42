/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:43:45 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/14 17:25:17 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	sort(int argc, char **argv)
{
	int		a;
	char	*aux;

	a = 2;
	while (a < argc)
	{
		if (ft_strcmp(argv[a - 1], argv[a]) == 1)
		{
			aux = argv[a - 1];
			argv[a - 1] = argv[a];
			argv[a] = aux;
			a = 1;
		}
		a++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	a;

	sort(argc, argv);
	i = 0;
	a = 1;
	while (a < argc)
	{
		while (argv[a][i] != '\0')
		{
			write(1, &argv[a][i], 1);
			i++;
		}
		write(1, "\n", 1);
		a++;
		i = 0;
	}
}
