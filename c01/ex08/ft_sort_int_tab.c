/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:21:40 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/01 09:22:37 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	aux;

	a = 0;
	while (a < size)
	{
		while (b < size)
		{
			if (tab[a] > tab[b])
			{
				aux = tab[a];
				tab[a] = tab[b];
				tab[b] = aux;
			}
			b++;
		}
		a++;
		b = a + 1;
	}
}
