/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:07:57 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/12 13:24:17 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORSEC_H
# define MORSEC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_morsec
{
	char	ascii;
	char	*morse;
}				t_morsec;

static const t_morsec	morsec_dict[26] = {
	{'a', ".-"}, {'b', "-..."},
	{'c', "-.-."}, {'d', "-.."},
	{'e', "."}, {'f', "..-."},
	{'g', "--."}, {'h',"...."},
	{'i', ".."}, {'j', ".---"},
	{'k', "-.-"}, {'l', ".-.."},
	{'m', "--"}, {'n', "-."},
	{'o', "---"}, {'p', ".--."},
	{'q', "--.-"}, {'r', ".-."},
	{'s', "..."}, {'t', "-"},
	{'u', "..-"}, {'v', "...-"},
	{'w', ".--"}, {'x', "-..-"},
	{'y', "-.--"}, {'z', "--.."}
};

void	putchar_fd(char c, int fd);
void	putstr_fd(char *s, int fd);

void	err_exit(char *message);

void	morse_to_ascii(char *morse_str);
void	ascii_to_morse(char *ascii_str);

#endif
