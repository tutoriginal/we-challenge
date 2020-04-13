/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_to_morse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:41:56 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 21:37:33 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

void		ft_show_morse(int index, t_final *t_fstr)
{
	if (index)
	{
		ft_show_morse(index / 2, t_fstr);
		if (index != 1)
		{
			if (index % 2)
				ft_stradd(t_fstr, "-");
			else
				ft_stradd(t_fstr, ".");
		}
	}
}

static int	ft_letters_a(char *words, t_final *t_fstr)
{
	char	*tank;
	int		index;
	int		index2;

	tank = TANK;
	index = 0;
	while (words[index])
	{
		index2 = 0;
		while (tank[index2] != words[index])
			index2++;
		ft_show_morse(index2, t_fstr);
		ft_stradd(t_fstr, " ");
		index++;
	}
	return (1);
}

static int	ft_check_str(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (!(isalpha(str[index])) && !ft_set_check(str[index], \
		ISSPACES))
			return (0);
		index++;
	}
	return (1);
}

int			ft_string_to_morse(char *str)
{
	t_final	t_strf;
	char	**words;

	if (!(ft_check_str(str)))
		return (ft_error(4));
	str = ft_strtoupper(str);
	ft_init(&t_strf);
	words = ft_split(str, ISSPACES);
	while (words && *words)
	{
		if (!ft_letters_a(*words, &t_strf) || !t_strf.ok)
		{
			free(t_strf.strf);
			return (ft_error(1));
		}
		++words;
		if (words && *words)
			ft_stradd(&t_strf, "/");
	}
	if (t_strf.ok)
		printf("%s\n", t_strf.strf);
	free(t_strf.strf);
	return (1);
}
