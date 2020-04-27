/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:16:57 by alyovano          #+#    #+#             */
/*   Updated: 2020/02/03 09:11:59 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len_digit(long long unsigned nb)
{
	int				l;

	l = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		l++;
	}
	return (l);
}

char				*ft_utoa(long long unsigned n)
{
	char					*str;
	long long unsigned		nb;
	int						i;
	char					*tab;

	tab = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("\0"));
	nb = n;
	i = len_digit(n) + 2;
	if (!(str = (char*)malloc(sizeof(char) * (i + 3))))
		return (NULL);
	str[i--] = '\0';
	str[0] = '0';
	str[1] = 'x';
	while (nb > 0)
	{
		str[i] = tab[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}
