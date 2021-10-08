/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:29:33 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/07 20:23:18 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	a;
	int	i;
	int	aux;

	a = 0;
	i = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	a = nb - 1;
	while (i < a)
	{
		aux = nb * nb--;
		i++;
	}
	return (nb);
}
