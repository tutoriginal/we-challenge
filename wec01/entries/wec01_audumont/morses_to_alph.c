/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morses_to_alph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:25:57 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 21:16:48 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		ft_set_check(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int		ft_is_morse_valid(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (!ft_set_check(str[index], MORSE) && !ft_set_check(str[index], \
		ISSPACES))
			return (0);
		index++;
	}
	return (1);
}
