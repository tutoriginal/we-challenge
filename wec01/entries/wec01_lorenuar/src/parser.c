/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:58 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 19:21:03 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

#define Z printf("<%d> input '%s' > '%c'\n",__LINE__, s, *s);

int		check_line(char *s)
{
	while (s && *s && !is_only(*s, BLANK))
	{
		s++;
	}
	if (s && *s && !is_only(*s, BLANK))
	{
		return (0);
	}
	while (s && *s && is_only(*s, BLANK))
	{
		s++;
	}
	if (s && *s && !is_only(*s, MORSE_DICT))
	{
		return (0);
	}
	while (s && *s && is_only(*s, MORSE_DICT))
	{
		s++;
	}
	if (s && *s && !is_only(*s, MORSE_DICT))
	{
		return (0);
	}
	return (1);
}

t_chain	*get_dict(char *filename)
{
	t_chain	*dict;
	t_chain	*temp;
	char	*line;
	int		fd;

	dict = NULL;
	temp = NULL;
	line = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		return (err_ptr("Dictionnary file invalid"));
	}
	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
		{
			str_del(&line);
			return (err_ptr("Dictionnary line not matching pattern"));
		}
		temp = new_node(new_dict(str_dupto(line, BLANK), \
		str_revdupto(line, BLANK)));
		if ((append_node(&dict, (void *)temp)) == NULL)
		{
			del_node(temp);
			str_del(&line);
			clear_dict(&dict);
			return (err_ptr("Can't append dictionnary node to chain"));
		}
		str_del(&line);
	}
	str_del(&line);
	return (dict);
}
