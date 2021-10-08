/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:46:35 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/07 17:37:43 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	a;
	int	l;

	i = 0;
	a = 0;
	if (to_find[0] == '\0')
		return (str);
	l = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		while (to_find[a] == str[i + a])
		{
			if (a == l - 1)
				return (str + i);
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}
