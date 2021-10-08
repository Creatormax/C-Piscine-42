/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:13:37 by hmorales          #+#    #+#             */
/*   Updated: 2021/09/25 16:15:30 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	lineprinter(int a, int b, int c, int d)
{
	if (d == 0)
	{
		if (c == 0)
			ft_putchar('A');
		else if (c > 0 && c < a - 1)
			ft_putchar('B');
		else if (c == a - 1)
			ft_putchar('C');
	}
	else if (d == b - 1)
	{
		if (c == 0)
			ft_putchar('C');
		else if (c > 0 && c < a - 1)
			ft_putchar('B');
		else if (c == a - 1)
			ft_putchar('A');
	}
	else if (d > 0 || d < b - 1)
	{				
		if (c == 0 || c == a - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}	
}

void	rush(int x, int y)
{
	int	n;
	int	m;

	m = 0;
	while (m <= y - 1)
	{
		n = 0;
		while (n <= x - 1)
		{
			lineprinter(x, y, n, m);
			n++;
		}					
		m++;
		ft_putchar('\n');
	}	
}
