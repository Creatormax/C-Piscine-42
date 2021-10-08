/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:51:31 by hmorales          #+#    #+#             */
/*   Updated: 2021/09/30 14:18:09 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	aux;

	a = 0;
	b = size - 1;
	while (a < (size / 2))
	{
		aux = tab[a];
		tab[a] = tab[b];
		tab[b] = aux;
		a++;
		b--;
	}
}
