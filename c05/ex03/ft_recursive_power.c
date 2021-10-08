/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:41:54 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/07 20:43:48 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	aux;

	aux = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{		
		return (nb * nb);
		power--;
	}
}
