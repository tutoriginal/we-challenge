/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:26:25 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 10:51:23 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char			*ft_zero(void)
{
	char			*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = 48;
	str[1] = '\0';
	return (str);
}

char				*ft_itoa_base_two(unsigned int n)
{
	char			*str;
	long			nb;
	int				i;
	char			*tab;

	tab = "0123456789abcdef";
	if (n == 0)
		return (ft_zero());
	if (!n)
		return (NULL);
	nb = n;
	i = len_digit(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (nb > 0)
	{
		str[i] = tab[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}
