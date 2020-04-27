/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:11:13 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 13:55:32 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_while_print(char c, int n)
{
	int i;

	i = 0;
	if (n < 0)
		return (0);
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
