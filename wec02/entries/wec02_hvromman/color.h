/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:16 by hvromman          #+#    #+#             */
/*   Updated: 2019/10/11 11:13:17 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <ctype.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct	s_all
{
	int		is_multicolor;
	int		r;
	int		g;
	int		b;
	int		term_width;
	int		term_height;
	int		line_length;
	int		pos_in_line;
	int		line_start_x;
	int		line_start_y;
	char	*line;
	char	buffer;
}				t_all;

int				move_to(int line, int column);
int				get_pos(int *y, int *x);

int				init(t_all *all);
int				flag_parser(t_all *all, int ac, char **av);

int				reader_loop(t_all *all);

int				usage(t_all *all);
int				exit_func(t_all *all, int exit_code);

int				print_lines(t_all *all);

#endif
