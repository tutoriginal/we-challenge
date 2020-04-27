/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:02:20 by alyovano          #+#    #+#             */
/*   Updated: 2019/11/01 13:34:21 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*finalstr;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!((finalstr = malloc(sizeof(char) * (size1 + size2 + 1)))))
		return (NULL);
	ft_memcpy(finalstr, s1, size1);
	ft_memcpy(finalstr + size1, s2, size2);
	finalstr[size1 + size2] = '\0';
	return (finalstr);
}
