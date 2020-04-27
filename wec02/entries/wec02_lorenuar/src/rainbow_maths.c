/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:59:04 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/25 00:05:56 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_irgb	hsv2rgb(double hue, double sat, double val)
{
	t_irgb	rgb;
	double	p;
	double	q;
	double	t;
	double	fract;

	(hue == 360.) ? (hue = 0.) : (hue /= 60.);
	fract = hue - (float)(int)hue;
	p = val * (1. - sat);
	q = val * (1. - sat * fract);
	t = val * (1. - sat * (1. - fract));
	if (0. <= hue && hue < 1.)
		rgb = (t_irgb){.r = val, .g = t, .b = p};
	else if (1. <= hue && hue < 2.)
		rgb = (t_irgb){.r = q, .g = val, .b = p};
	else if (2. <= hue && hue < 3.)
		rgb = (t_irgb){.r = p, .g = val, .b = t};
	else if (3. <= hue && hue < 4.)
		rgb = (t_irgb){.r = p, .g = q, .b = val};
	else if (4. <= hue && hue < 5.)
		rgb = (t_irgb){.r = t, .g = p, .b = val};
	else if (5. <= hue && hue < 6.)
		rgb = (t_irgb){.r = val, .g = p, .b = q};
	else
		rgb = (t_irgb){.r = 0., .g = 0., .b = 0.};
	return (rgb);
}

int		puts_rainbow(double freq, double phase)
{
	int		r;
	char	*s;
	size_t	slen;
	double	hue;
	t_irgb	col;
	size_t	i;

	r = 0;
	s = NULL;
	while ((r = get_next_line(0, &s)))
	{
		slen = str_len(s);
		hue = phase;
		i = 0;
		while (i < slen && s)
		{
			col = hsv2rgb(hue, 1, 1);
			printf("\x1b[38;2;%d;%d;%dm%c",
			(int)(col.r * 255.0),
			(int)(col.g * 255.0),
			(int)(col.b * 255.0), s[i++]);
			hue += (360.0 * freq) / slen;
			if (hue >= 360)
			{
				hue -= 360;
			}
		}
		puts("\x1b[0m");
		free(s);
	}
	free(s);
	if (r == -1)
	{
		return (err("get_next_line allocation"));
	}
	return (0);
}
