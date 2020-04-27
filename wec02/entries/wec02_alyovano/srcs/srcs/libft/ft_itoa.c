/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:53 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/15 15:30:38 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb >= 10 || nb <= -10)
	{
		i++;
		nb = (nb / 10);
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	temp;

	len = ft_num_len(n);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = len - 1;
	if (n < 0)
	{
		str[0] = '-';
		temp = (unsigned int)(n * -1);
	}
	else
		temp = (unsigned int)n;
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
