/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:53:33 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/29 16:17:21 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	sz;

	if (!haystack || !needle)
		return (NULL);
	if (!(*needle))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	sz = ft_strlen(needle);
	while (*haystack != '\0' && i <= (len - sz))
	{
		if (ft_strncmp(haystack, needle, sz) == 0)
			return (char*)(haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
