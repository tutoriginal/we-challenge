/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:47:18 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:05:03 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Putstr_len imprime la str jusqu a len
** Elle renvoie 1 si len a ete atteinte et 0 si \0 a ete atteint
** -1 est retourné en cas d'erreur
*/

int				ft_putstr_len(char *str, unsigned int len)
{
	unsigned int i;

	i = 0;
	if (!str || !*str || len == 0)
		return (-1);
	while (i < len)
	{
		i++;
		if (str[i] == '\0')
		{
			write(1, str, i);
			return (i);
		}
	}
	write(1, str, i);
	return (i);
}
