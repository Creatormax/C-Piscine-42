/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:41:16 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/14 11:29:51 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 3;
	if (nb == 2)
		return (1);
	if (nb <= 0 || nb == 1 || nb % 2 == 0)
		return (0);
	while (n < 46341 && nb >= n * n)
	{
		if (nb % n == 0)
			return (0);
		n += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
	{
		nb++;
		while (ft_is_prime(nb) == 0)
			nb++;
	}
	return (nb);
}
