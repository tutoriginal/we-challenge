/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_morse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:23:15 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/12 13:41:25 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

static void	ascii_checker(char *ascii_str)
{
	size_t		i;

	i = 0;
	while (ascii_str[i])
	{
		if (ascii_str[i] != ' ' && (ascii_str[i] > 'z' || ascii_str[i] < 'a'))
			err_exit("Invalid arguments\n");
		i++;
	}
}

void		ascii_to_morse(char *ascii_str)
{
	size_t		i;

	ascii_checker(ascii_str);
	if (ascii_str[0] == ' ')
		putchar_fd('/', 1);
	else
		putstr_fd(morsec_dict[ascii_str[0] - 'a'].morse, 1);
	for (i = 1; i < strlen(ascii_str); i++)
	{
		putchar_fd(' ', 1);
		if (ascii_str[i] == ' ')
		putchar_fd('/', 1);
	else
		putstr_fd(morsec_dict[ascii_str[i] - 'a'].morse, 1);
	}
}
