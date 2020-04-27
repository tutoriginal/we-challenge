/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:31:08 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/15 15:39:53 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(unsigned int nb)
{
	int i;

	i = 1;
	while (nb >= 10)
	{
		i++;
		nb = (nb / 10);
	}
	return (i);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	temp;

	len = ft_num_len(n);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = len - 1;
	temp = n;
	while (temp >= 10)
	{
		str[i] = (temp % 10) + 48;
		temp = temp / 10;
		i--;
	}
	str[i] = (temp % 10) + 48;
	str[len] = '\0';
	return (str);
}
