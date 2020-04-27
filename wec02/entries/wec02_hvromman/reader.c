/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:16 by hvromman          #+#    #+#             */
/*   Updated: 2019/10/11 11:13:17 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int		start_line(t_all *all)
{
	all->line_length = 0;
	all->pos_in_line = 0;
	get_pos(&all->line_start_y, &all->line_start_x);
	if (all->line_start_y == all->term_height - 1)
	{
		printf("\n");
		all->line_start_y--;
		move_to(all->line_start_y, all->line_start_x);
		fflush(stdout);
	}
	return (0);
}

static int		get_escape(t_all *all)
{
	int		ret;

	ret = read(STDIN_FILENO, &all->buffer, 1);
	if (ret != 1 || all->buffer != '[')
		return (-1);
	ret = read(STDIN_FILENO, &all->buffer, 1);
	if (ret != 1 || !(all->buffer == 'C' || all->buffer == 'D'))
		return (-1);
	if (all->buffer == 'C' && all->pos_in_line < all->line_length)
		all->pos_in_line++;
	else if (all->buffer == 'D' && all->pos_in_line)
		all->pos_in_line--;
	return (0);
}

static int		handle_char(t_all *all)
{
	if (all->buffer == '\n')
		return (1);
	else if (all->buffer == 4)
		printf("\n\n") && exit_func(all, 0);
	else if (all->buffer == 127 && all->pos_in_line > 0)
	{
		memmove(all->line + all->pos_in_line - 1, all->line + all->pos_in_line,
			all->line_length - all->pos_in_line + 1);
		all->pos_in_line--;
		all->line_length--;
	}
	else if (all->buffer == 127)
		return (0);
	else if (all->buffer == '\e')
		get_escape(all);
	else
	{
		memmove(all->line + all->pos_in_line + 1, all->line + all->pos_in_line,
			all->line_length - all->pos_in_line + 1);
		all->line[all->pos_in_line] = all->buffer;
		all->pos_in_line++;
		all->line_length++;
	}
	return (0);
}

int				reader_loop(t_all *all)
{
	int		ret;

	while (19)
	{
		start_line(all);
		while ((ret = read(STDIN_FILENO, &all->buffer, 1)) > 0)
		{
			if (handle_char(all) > 0)
				break ;
			print_lines(all);
			if (all->line_length == all->term_width)
				break ;
		}
		move_to(all->line_start_y + 1, all->line_start_x);
		printf("\n");
		if (ret == -1)
			exit_func(all, -3);
		else if (ret == 0)
			exit_func(all, 0);
	}
	return (0);
}
