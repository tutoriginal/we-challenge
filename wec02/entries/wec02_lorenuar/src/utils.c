/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:09:55 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/25 17:47:08 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		str_tol(const char *s)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (s && ((*s >= '\t' && *s <= '\r') || *s == ' '))
		s++;
	if (s && *s == '-')
		sign = -1;
	if (s && (*s == '-' || *s == '+'))
		s++;
	while (s && *s >= '0' && *s <= '9')
		num = (num * 10) + (*s++ - '0');
	if (num > LONG_MAX)
		return ((sign == 1) ? -1 : 0);
	return ((sign == 1) ? num : -num);
}

size_t	str_len(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int		str_cmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		checkinput(char *s)
{
	size_t	i;
	ssize_t	n;

	if (!s)
	{
		return (0);
	}
	i = 0;
	while (s && s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return (err("Input not a positive integer"));
		}
		i++;
	}
	n = str_tol(s);
	if (n >= 0 && n <= 255)
	{
		return (0);
	}
	return (err("Number out of range (0-255)"));
}

int		checkinputdouble(char *s)
{
	size_t	i;
	ssize_t	n;

	if (s == NULL)
	{
		return (err("Input is NULL"));
	}
	i = 0;
	while (s && s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			return (err("Not a positive floating point number"));
		}
		i++;
	}
	n = strtod(s, NULL);
	if (n >= 0 && n <= DBL_MAX)
	{
		return (0);
	}
	return (err("Number out of range (0-""DBL_MAX"")"));
}

void	put_color(t_rgb input, int bg_fg)
{
	int	r;
	int	g;
	int	b;

	r = str_tol(input.r);
	g = str_tol(input.g);
	b = str_tol(input.b);
	if (input.r == NULL ||
		input.g == NULL ||
		input.b == NULL)
	{
		return ;
	}
	if (bg_fg == BG)
	{
		printf("\x1b[48;2;%d;%d;%dm", r, g, b);
	}
	else if (bg_fg == FG)
	{
		printf("\x1b[38;2;%d;%d;%dm", r, g, b);
	}
}

int		err(char *s)
{
	printf("\x1b[31;1mError : %s\x1b[0m\n", s);
	return (1);
}

void	put_usage(char *s)
{
	printf("\nUsage :\n"
	"\t%s [R(0-255)] [G(0-255] [B(0-255)]       "
	"                               - Set foreground color only\n"
	"\t%s -b [R(0-255)] [G(0-255] [B(0-255)]    "
	"                               - Set background color only\n"
	"\t%s -b [R(0-255)] [G(0-255] [B(0-255)] [R(0-255)] [G(0-255] "
	"[B(0-255)]   - Set background and foreground color\n"
	"\t%s -r                                    "
	"                               - Special rainbow mode\n"
	"\t%s -rfreq [frequency factor]             "
	"                               - Rainbow mode with frequency factor\n"
	"\t%s -rfreq [frequency factor] -rphase [phase offset (360 degrees)]"
	"       - Rainbow mode with frequency factor and phase offset\n"
	"\n\n"
	, s, s, s, s, s, s);
}
