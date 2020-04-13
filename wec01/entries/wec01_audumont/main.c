/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 10:39:47 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 21:39:03 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int			ft_letters(char *words, t_final *t_strf)
{
	char	*tank;
	size_t	strl;
	int		index;
	size_t	x;
	char	*strc;

	tank = TANK;
	strl = strlen(tank);
	index = 0;
	x = 1;
	while (words[index])
	{
		if (words[index] == '-')
		{
			x = x << 1;
			x = x + 1;
		}
		if (words[index] == '.')
			x = x << 1;
		if (words[index] == ' ')
		{
			if (x < strl && tank[x] != '*')
			{
				strc = ft_c_to_str(tank[x]);
				ft_stradd(t_strf, strc);
				free(strc);
			}
			else
			{
				t_strf->ok = 0;
				return (ft_error(1));
			}
			x = 1;
		}
		index++;
	}
	if (x < strl && tank[x] != '*')
	{
		strc = ft_c_to_str(tank[x]);
		ft_stradd(t_strf, strc);
		free(strc);
	}
	return (1);
}

int			ft_morse_to_string(char *str)
{
	t_final		t_strf;
	char		**words;

	if (!ft_is_morse_valid(str))
		return (ft_error(2));
	ft_init(&t_strf);
	words = ft_split(str, "/");
	while (words && *words)
	{
		if (!ft_letters(*words, &t_strf) || !t_strf.ok)
		{
			free(t_strf.strf);
			return (ft_error(1));
		}
		++words;
		if (words && *words)
			ft_stradd(&t_strf, " ");
	}
	if (t_strf.ok)
	{
		t_strf.strf = ft_strtolower(t_strf.strf);
		printf("%s\n", t_strf.strf);
	}
	free(t_strf.strf);
	return (1);
}

int			main(int argc, char **argv)
{
	int			index;

	index = 1;
	if (argc >= 2)
	{
		while (index < argc)
		{
			if (argc >= 3 && !strcmp(argv[1], "-r"))
			{
				(index == 1) ? index++ : index;
				if (!(ft_string_to_morse(argv[index])))
					return (0);
			}
			else
			{
				if (!ft_morse_to_string(argv[index]))
					return (0);
			}
			index++;
		}
		return (1);
	}
	else
		return (ft_error(3));
	return (0);
}
