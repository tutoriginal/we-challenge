/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:48:31 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/28 13:27:39 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_total;
	size_t	i;
	size_t	j;

	i = 0;
	size_total = ft_strlen(dst) + ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
	{
		j = ft_strlen(dst);
		while (src[i] != '\0' && j < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
		return (size_total);
	}
}
