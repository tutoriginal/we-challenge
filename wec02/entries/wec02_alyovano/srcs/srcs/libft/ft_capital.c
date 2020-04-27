/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capital.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:13:01 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/15 12:13:31 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_print_capitalstr(char *str)
{
	int		i;
	char	a[35];

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		a[i] = str[i];
		i++;
	}
	a[i] = '\0';
	i = 0;
	while (a[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
