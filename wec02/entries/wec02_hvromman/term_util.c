/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:16 by hvromman          #+#    #+#             */
/*   Updated: 2019/10/11 11:13:17 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int			move_to(int line, int column)
{
	printf("\e[%d;%dH", line + 1, column + 1);
	return (0);
}

static int	get_pos_reader(char *buf, int *x, int *y, int i)
{
	int		pow;

	i -= 2;
	pow = 1;
	while (buf[i] != ';')
	{
		*x = *x + (buf[i] - '0') * pow;
		i--;
		pow *= 10;
	}
	(*x)--;
	i--;
	pow = 1;
	while (buf[i] != '[')
	{
		*y = *y + (buf[i] - '0') * pow;
		i--;
		pow *= 10;
	}
	(*y)--;
	return (0);
}

int			get_pos(int *y, int *x)
{
	char	buf[30];
	int		i;
	char	ch;

	buf[0] = 0;
	*y = 0;
	*x = 0;
	write(1, "\e[6n", 4);
	ch = 0;
	i = 0;
	while (ch != 'R')
	{
		if (!read(0, buf + i, 1))
			return (1);
		ch = buf[i];
		i++;
	}
	if (i < 2)
		return (1);
	return (get_pos_reader(buf, x, y, i));
}
