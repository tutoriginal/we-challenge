/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:40:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/12 21:41:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

/*
** Invalid characters are replaced by '?'
*/

static void		ft_interpret(const char *str, t_list *dict)
{
	t_list	*dict_copy;
	int		valid;
	int		i;

	while (*str)
	{
		valid = 0;
		i = 0;
		while (str[i] == '-' || str[i] == '.')
			i++;
		dict_copy = dict;
		while (dict_copy && i > 0)
		{
			if (!strncmp(&(((char*)dict_copy->content)[2]), str, i)
				&& ((char*)dict_copy->content)[2 + i] == 0 && (valid = 1))
				putchar(*((char*)dict_copy->content) + 32);
			dict_copy = dict_copy->next;
		}
		if ((str += i) && !valid)
			write(1, "?", 1);
		while (*str == ' ' || *str == '/')
			if (*str++ == '/')
				write(1, " ", 1);
	}
	write(1, "\n", 1);
}

static void		ft_morse(const char *str, t_list *dict)
{
	int		valid;
	t_list	*dict_copy;

	while (*str)
	{
		valid = 0;
		dict_copy = dict;
		while (dict_copy)
		{
			if (((char*)(dict_copy->content))[0] == *str - 32 && (valid = 1))
				write(1, &(((char*)dict_copy->content)[2]),
				strlen(&(((char*)dict_copy->content)[2])));
			dict_copy = dict_copy->next;
		}
		if (*str == ' ')
			write(1, "/", 1);
		else if (!valid)
			write(1, "?", 1);
		if (*(++str))
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int				main(int argc, char const *argv[])
{
	int		fd;
	char	*line;
	t_list	*dict;

	if (argc == 2 || (argc == 3 && !strncmp("-r", argv[1], 3)))
	{
		if (!(fd = open("dictionary.txt", O_RDONLY)))
			return (1);
		get_next_line(fd, &line);
		dict = ft_lstnew(((void *)line));
		while (get_next_line(fd, &line))
			ft_lstadd_back(&dict, ft_lstnew((void *)line));
		free(line);
		close(fd);
		(argc == 2) ? ft_interpret(argv[1], dict) : ft_morse(argv[2], dict);
		ft_lstclear(&(dict), free);
	}
	else if (argc == 3 && !strncmp("-wav", argv[1], 5))
		ft_wav(argv[2]);
	else
		write(1, "ERROR\n", 6);
	return (0);
}
