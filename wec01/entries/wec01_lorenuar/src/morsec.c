/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 18:43:24 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		morsec(int direction, char *input)
{
	t_chain *dict;
	char	*resl;

	dict = NULL;
	resl = NULL;
	if (!(dict = get_dict("dict_wikipedia.txt")))
	{
		clear_dict(&dict);
		return (err("Error : Dictionnary error"));
	}
	if (direction == 1)
	{
		if ((resl = rev_translator(dict, input)) == NULL)
		{
			clear_dict(&dict);
			str_del(&resl);
			return (err("ASCII to MORSE"));
		}
		puts(resl);
		str_del(&resl);
	}
	if (direction == 0)
	{
		if ((resl = translator(dict, input)) == NULL)
		{
			clear_dict(&dict);
			str_del(&resl);
			return (err("MORSE to ASCII"));
		}
		puts(resl);
		str_del(&resl);
	}
	clear_dict(&dict);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (morsec(0, argv[1]))
		{
			return (err("Morsec normal"));
		}
	}
	else if (argc == 3 && strncmp(argv[1], "-r", 3) == 0)
	{
		if (morsec(1, argv[2]))
		{
			return (err("Morsec reverse"));
		}
	}
	else
	{
		return (err("Inccorrect number of arguments given"\
		"Usage : ./morsec \"MORSE to ASCII\" | -r \"ASCII to MORSE\"\n"));
	}
	return (0);
}
