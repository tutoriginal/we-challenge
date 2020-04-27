/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:16 by hvromman          #+#    #+#             */
/*   Updated: 2019/10/11 11:13:17 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int		print_color(t_all *all)
{
	int		i;

	if (all->is_multicolor)
	{
		for (i = 0; i < all->line_length; ++i)
		printf("\e[%dm%c", 91 + i % 6, all->line[i]);
		if (i < all->term_width)
			printf("%c", ' ');
	}
	else
		printf("\e[38;2;%d;%d;%dm%.*s%*s", all->r, all->g, all->b,
			all->line_length, all->line,
			all->term_width - all->line_length != 0, "");
	return (0);
}

int				print_lines(t_all *all)
{
	move_to(all->line_start_y, all->line_start_x);
	printf("\e[0m%.*s%*s", all->line_length, all->line,
		all->term_width - all->line_length != 0, "");
	move_to(all->line_start_y + 1, all->line_start_x);
	print_color(all);
	move_to(all->line_start_y, all->line_start_x + all->pos_in_line);
	fflush(stdout);
	return (0);
}
