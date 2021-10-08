/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:48:48 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/07 17:08:20 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	compruebo(void)
{
	write(1, "-", 1);
	write(1, "2", 1);
	write(1, "1", 1);
	write(1, "4", 1);
	write(1, "7", 1);
	write(1, "4", 1);
	write(1, "8", 1);
	write(1, "3", 1);
	write(1, "6", 1);
	write(1, "4", 1);
	write(1, "8", 1);
}

void	desgloso(int nb, int aux, int l)
{
	int		pot;
	int		cont;
	int		a;
	char	i;

	cont = 0;
	pot = 1;
	while (aux % l != aux)
	{
		pot = pot * l;
		cont++;
		aux = aux / l;
	}
	a = 0;
	while (a <= cont)
	{
		i = nb / pot + '0';
		write(1, &i, 1);
		nb = nb % pot;
		pot = pot / l;
		a++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	aux;
	int	l;

	l = ft_strlen(base);
	if (nbr == -2147483648)
		compruebo();
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * (-1);
		}
		aux = nbr;
		desgloso(nbr, aux, l);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	n;

	i = 0;
	neg = 1;
	n = 0;
	while ((str[i] <= '\r' && str[i] >= '\t') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i] - '0') + (n * 10);
		i++;
	}
	ft_putnbr_base(n, base);
	return (n * neg);
}
