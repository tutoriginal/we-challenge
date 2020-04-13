/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morse_to_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:41:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/12 13:41:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

static void	morse_checker(char *morse_str)
{
	size_t		i;

	i = 0;
	while (morse_str[i])
	{
		if (morse_str[i] != '.' && morse_str[i] != '-' &&
		morse_str[i] != ' ' && morse_str[i] != '/')
			err_exit("Invalid arguments\n");
		i++;
	}
}

void		morse_to_ascii(char *morse_str)
{
	size_t		i;
	char	*word;

	morse_checker(morse_str);
	do
	{
		word = strsep(&morse_str, " ");
		if (word)
		{
			if (word[0] == '/')
				putchar_fd(' ', 1);
			else
			{
				i = 0;
				while (i < 26)
				{
					if (!strcmp(morsec_dict[i].morse, word))
					{
						putchar_fd(morsec_dict[i].ascii, 1);
						i = 26;
					}
					i++;
				}
			}
		}
	}
	while (word);
}
