/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:47:05 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/28 10:55:01 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	unsigned char		*source;
	size_t				i;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	if (!dst || !src)
		return (NULL);
	if (dest == source)
		return (dest);
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
			return ((unsigned char*)(dest + (i + 1)));
		i++;
	}
	return (NULL);
}
