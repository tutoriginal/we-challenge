/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:45:35 by alyovano          #+#    #+#             */
/*   Updated: 2019/11/01 14:10:51 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_cut(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t debut;
	size_t fin;

	if (s1 == NULL || set == NULL)
		return (NULL);
	debut = 0;
	fin = ft_strlen(s1) - 1;
	while (count_cut(set, s1[debut]) == 1)
		debut++;
	while (count_cut(set, s1[fin]) == 1 && fin > debut)
		fin--;
	return (ft_substr(s1, debut, (fin - debut) + 1));
}
