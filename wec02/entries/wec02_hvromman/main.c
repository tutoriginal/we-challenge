/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:16 by hvromman          #+#    #+#             */
/*   Updated: 2019/10/11 11:13:17 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		exit_func(t_all *all, int exit_code)
{
	free(all->line);
	exit(exit_code);
}

int		usage(t_all *all)
{
	fprintf(stderr, "usage: ./color [-r] [r g b]\n"
					"       -r: output in rainbow mode\n"
					"       r, g, b: values for rgb mode (0-255)\n");
	exit_func(all, -1);
	return (0);
}

int		main(int ac, char **av)
{
	t_all	all;

	init(&all);
	flag_parser(&all, ac, av);
	reader_loop(&all);
	exit_func(&all, 0);
}
