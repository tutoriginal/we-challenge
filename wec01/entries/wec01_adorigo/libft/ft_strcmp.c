/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:21:16 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 13:50:02 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;
	size_t	len2;
	int		result;
	
	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (-1);
	else if (s1 && !s2)
		return (1);
	len = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	len = (len <= len2) ? len : len2;
	result = ft_memcmp(s1, s2, len);
	return (result);
}
