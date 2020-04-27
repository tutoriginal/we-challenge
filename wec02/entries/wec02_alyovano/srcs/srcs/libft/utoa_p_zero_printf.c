/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_p_zero_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:17:42 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 10:54:27 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_boucle_while(char *str, long nb, int i, char *tab)
{
	while (nb > 0)
	{
		str[i] = tab[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}

static int			len_digit(long nb)
{
	int				l;

	l = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 16;
		l++;
	}
	return (l);
}

char				*ft_utoa_p_zero_printf(unsigned long n, int precision)
{
	char			*str;
	long			nb;
	int				i;
	char			*tab;

	tab = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("\0"));
	nb = n;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (i + 32))))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	while (i + 2 < precision)
	{
		str[i] = '0';
		i++;
	}
	i = i + len_digit(n) + 1;
	str[i] = '\0';
	str = ft_boucle_while(str, nb, i, tab);
	return (str);
}
