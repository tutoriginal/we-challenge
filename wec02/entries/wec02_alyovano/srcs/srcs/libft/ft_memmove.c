/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:20:27 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/28 11:09:03 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*source;
	unsigned char		*s;
	unsigned char		*d;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	s = source + (len - 1);
	d = dest + (len - 1);
	if ((dest == NULL || src == NULL) || dst == src)
		return (NULL);
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
