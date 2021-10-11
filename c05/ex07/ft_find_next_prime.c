/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:41:16 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/11 18:56:10 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 3;
	if (nb <= 0 || nb == 1 || nb % 2 == 0)
		return (0);
	while (n < 46340 && nb >= n * n)
	{
		if (nb % n == 0)
			return (0);
		n += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (ft_is_prime(nb) == 0)
		return (0);
	nb++;
	while (i == 0)
	{
		i = ft_is_prime(nb);
		nb++;
	}
	return (nb - 1);
}
