/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:10:08 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/29 16:50:24 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len_s2;
	size_t len_s1;
	size_t len;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2) + 1;
	len = len_s1;
	if (len_s1 > len_s2)
		len = len_s2;
	if (len > n)
		return (ft_memcmp(s1, s2, n));
	return (ft_memcmp(s1, s2, len));
}
