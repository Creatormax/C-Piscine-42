/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:29:33 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/11 13:46:12 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	a;
	int	i;
	int	aux;

	i = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		a = nb;
		aux = nb;
		while (i < a && nb > 1)
		{
			aux *= (nb - 1);
			nb--;
			i++;
		}
		return (aux);
	}	
}
