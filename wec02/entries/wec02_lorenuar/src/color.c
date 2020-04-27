/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:40:16 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/25 17:45:03 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		puts_color(t_rgb fg, t_rgb bg)
{
	int		r;
	char	*s;

	s = NULL;
	if (checkinput(fg.r) || checkinput(fg.g) || checkinput(fg.b) ||
		checkinput(bg.r) || checkinput(bg.g) || checkinput(bg.b))
	{
		return (err("Invalid input"));
	}
	while ((r = get_next_line(0, &s)))
	{
		put_color(fg, FG);
		put_color(bg, BG);
		printf("%s\x1b[0m\n", s);
		free(s);
	}
	free(s);
	if (r == -1)
	{
		return (err("get_next_line allocation"));
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 4 && str_cmp(argv[3], "-rphase"))
	{
		if (puts_color((t_rgb){argv[1], argv[2], argv[3]},
		(t_rgb){NULL, NULL, NULL}))
		{
			put_usage(argv[0]);
			return (1);
		}
	}
	else if ((argc == 5 || argc == 8) && !str_cmp(argv[1], "-b"))
	{
		if (argc == 5)
		{
			if (puts_color((t_rgb){NULL, NULL, NULL},
			(t_rgb){argv[2], argv[3], argv[4]}))
			{
				put_usage(argv[0]);
				return (1);
			}
		}
		else if (argc == 8)
		{
			if (puts_color((t_rgb){argv[5], argv[6], argv[7]},
			(t_rgb){argv[2], argv[3], argv[4]}))
			{
				put_usage(argv[0]);
				return (1);
			}
		}
	}
	else if (argc == 2 && !str_cmp(argv[1], "-r"))
	{
		if (puts_rainbow(1.0, 0))
		{
			put_usage(argv[0]);
			return (1);
		}
	}
	else if (argc == 3 && !str_cmp(argv[1], "-rfreq"))
	{
		if (checkinputdouble(argv[2]))
		{
			put_usage(argv[0]);
			return (err("Invalid input"));
		}
		if (puts_rainbow(strtod(argv[2], NULL), 0))
		{
			put_usage(argv[0]);
			return (1);
		}
	}
	else if (argc == 5 && !str_cmp(argv[1], "-rfreq") &&
	!str_cmp(argv[3], "-rphase"))
	{
		if (checkinputdouble(argv[2]) ||
			checkinputdouble(argv[4]))
		{
			put_usage(argv[0]);
			return (err("Invalid input"));
		}
		if (puts_rainbow(strtod(argv[2], NULL), strtod(argv[4], NULL)))
		{
			put_usage(argv[0]);
			return (1);
		}
	}
	else
	{
		put_usage(argv[0]);
		return (1);
	}
	return (0);
}
