/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:16 by hvromman          #+#    #+#             */
/*   Updated: 2019/10/11 11:13:17 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int		check_arg(t_all *all, char *arg)
{
	int		value;
	size_t	i;

	for (i = 0; i < strlen(arg); i++)
	{
		if (!isdigit(arg[i]))
			usage(all);
		if (i > 2)
			usage(all);
	}
	value = atoi(arg);
	if (value > 255)
		usage(all);
	return (value);
}

int				flag_parser(t_all *all, int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "-r") == 0)
	{
		all->is_multicolor = 1;
	}
	else if (ac == 4)
	{
		all->r = check_arg(all, av[1]);
		all->g = check_arg(all, av[2]);
		all->b = check_arg(all, av[3]);
	}
	else
	{
		usage(all);
	}
	return (0);
}

int				init(t_all *all)
{
	struct termios	org_opts;
	struct ttysize	ts;

	bzero(all, sizeof(*all));
	ioctl(0, TIOCGSIZE, &ts);
	all->term_width = ts.ts_cols;
	all->term_height = ts.ts_lines;
	tcgetattr(0, &org_opts);
	org_opts.c_lflag = (ISIG | OFDEL | IEXTEN) & ~(ICANON);
	tcsetattr(0, TCSANOW, &org_opts);
	if (!(all->line = malloc((all->term_width + 1) * sizeof(char))))
		exit_func(all, -2);
	return (0);
}
