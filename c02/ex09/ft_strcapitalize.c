/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:47:17 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/05 18:51:25 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	control;

	i = 0;
	while (str[i] != '\0')
	{
		control = 1;
		if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z'))
			control = 0;
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			control = 0;
		if (control == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if (control == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
