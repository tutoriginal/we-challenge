/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:09:38 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/12 13:40:06 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		main(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
		err_exit("Invalid arguments\n");
	if (argc == 2)
		morse_to_ascii(argv[1]);
	else if (argc == 3 && !strcmp(argv[1], "-r"))
		ascii_to_morse(argv[2]);
	else
		err_exit("Invalid arguments\n");
	putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
}
