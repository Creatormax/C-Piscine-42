/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:34:45 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/06 17:43:36 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != 0)
	{
		n++;
	}
	return (n);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				ssrc;
	int				sdest;
	unsigned int	i;
	unsigned int	max;

	ssrc = ft_strlen(src);
	sdest = ft_strlen(dest);
	i = 0;
	if (size < (unsigned int) sdest + 1)
	{
		*(dest + sdest) = '\0';
		return (ssrc + size);
	}
	else
	{
		max = size - sdest - 1;
		while (i < max && *(src + i) != 0)
		{
			*(dest + sdest + i) = *(src + i);
			i++;
		}
		*(dest + sdest + i) = '\0';
		return (ssrc + sdest);
	}
}
