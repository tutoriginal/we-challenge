/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:01:43 by alyovano          #+#    #+#             */
/*   Updated: 2019/11/04 14:40:37 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*stockdst;
	unsigned char	*stocksrc;
	size_t			count;

	stocksrc = (unsigned char*)src;
	stockdst = (unsigned char*)dst;
	count = 0;
	if (!dst && !src)
		return (NULL);
	while (count < n)
	{
		stockdst[count] = stocksrc[count];
		count++;
	}
	return (stockdst);
}
