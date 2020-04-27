/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:00:36 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/15 15:16:50 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_int(size_t n)
{
	int		size;

	size = 1;
	while (n >= 16)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char		*ft_itoa_base(unsigned long long n, char *base)
{
	char					*returned_value;
	int						len;
	size_t					i;
	unsigned long long		tmp;

	len = size_int(n);
	if (!(returned_value = (char*)ft_calloc((size_t)len + 1, sizeof(char))))
		return (NULL);
	i = len - 1;
	if (n == 0)
		returned_value[i--] = '0';
	while (n > 0)
	{
		tmp = 0;
		tmp = n % 16;
		if (tmp < 10)
			returned_value[i--] = (char)tmp + '0';
		else
			returned_value[i--] = base[tmp];
		n /= 16;
	}
	returned_value[len] = '\0';
	return (returned_value);
}
