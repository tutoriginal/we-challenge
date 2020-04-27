/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:41:52 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/28 11:47:42 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char*)s + len);
		len--;
	}
	return (NULL);
}
