/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:51:19 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 21:35:39 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

char		*ft_c_to_str(char c)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return ((char *)str);
}

char		*ft_strtoupper(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		str[index] = toupper(str[index]);
		index++;
	}
	return (str);
}

char		*ft_strtolower(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		str[index] = tolower(str[index]);
		index++;
	}
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		total;
	char	*resp;

	if (!s1 || !s2)
		return (NULL);
	total = strlen(s1) + strlen(s2);
	resp = (char*)malloc(sizeof(char) * (total + 1));
	if (!resp)
		return (0);
	dest = resp;
	if (s1)
		while (*s1)
			*dest++ = *s1++;
	if (s2)
		while (*s2)
			*dest++ = *s2++;
	*dest = '\0';
	return (resp);
}
