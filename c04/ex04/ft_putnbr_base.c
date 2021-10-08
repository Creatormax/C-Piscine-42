/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:42:44 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/07 16:50:24 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	desgloso(int nb, int aux, int l)
{
	int	pot;
	int	cont;
	int	a;

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
		ft_putchar(nb / pot + '0');
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
