/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wec00_lorenuar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:15:13 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/07 17:39:48 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#ifndef VERBOSE
# define VERBOSE 0
#endif

#if VERBOSE == 1
# include <stdio.h>
# include <stdarg.h>
#endif

#ifndef N_THREADS
# define N_THREADS	50
#endif

struct		s_tchain
{
	pthread_t		thid;
	char			*str;
	size_t			res;
	struct s_tchain	*next;
};
typedef	struct s_tchain	t_tchain;

#if VERBOSE == 1

void		verbose(char *format, ...)
{
	va_list	args;

	va_start(args, format);
	if (VERBOSE)
	{
		printf(format, args);
	}
	va_end(args);
}

#else

void		verbose(char *f, ...)
{
	(void)f;
	return ;
}

#endif

t_tchain	*new_tchain(char *str)
{
	t_tchain	*new;

	new = NULL;
	if (!(new = (t_tchain*)malloc(sizeof(t_tchain))))
	{
		return (NULL);
	}
	new->str = str;
	new->next = NULL;
	return (new);
}

void		append_tchain(t_tchain **chain, t_tchain *link)
{
	t_tchain *tmp;

	tmp = NULL;
	if (chain && *chain && link)
	{
		tmp = *chain;
		while (link && tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = link;
	}
	else if (chain)
	{
		*chain = link;
	}
}

size_t		size_tchain(t_tchain *chain)
{
	size_t	size;

	size = 0;
	while (chain)
	{
		chain = chain->next;
		size++;
	}
	return (size);
}

void		del_tchain(t_tchain *link)
{
	if (link)
	{
		free(link->str);
		link->str = NULL;
		free(link->next);
		link->next = NULL;
		free(link);
		link = NULL;
	}
}

void		clear_tchain(t_tchain **chain)
{
	t_tchain *tmp;

	while (chain && *chain)
	{
		tmp = (*chain)->next;
		del_tchain(*chain);
		*chain = tmp;
	}
}

void		print_tchain(t_tchain *chain)
{
	t_tchain	*tmp;
	size_t		i;

	tmp = chain;
	i = 0;
	if (!tmp)
	{
		verbose("NULL");
		return ;
	}
	verbose("\nChain :");
	while (tmp)
	{
		verbose("<%lu> \t [link * %p | thread id %lu | str \"%s\" "\
		"| result %lu | next *> %p]\n", \
		i, tmp, tmp->thid, tmp->str, tmp->res, tmp->next);
		i++;
		tmp = tmp->next;
	}
	verbose(">> Chain of %lu link(s) <<\n", size_tchain(chain));
}

void		*thread_len(void *arg)
{
	t_tchain	*link;
	size_t		len;

	link = (t_tchain *)arg;
	len = 0;
	while (link->str && link->str[len])
	{
		len++;
	}
	link->res = len;
	pthread_exit(NULL);
}

size_t		ft_strlen(char *str)
{
	size_t		i;
	t_tchain	*head;
	t_tchain	*tmp;
	size_t		old_value;

	head = NULL;
	tmp = NULL;
	if (!str)
	{
		return (0);
	}
	i = 0;
	while (i < N_THREADS)
	{
		append_tchain(&head, new_tchain(str));
		verbose("\r<%lu> append", i);
		i++;
	}
	tmp = head;
	while (tmp)
	{
		if (pthread_create(&tmp->thid, NULL, thread_len, (void *)tmp))
		{
			return (0);
		}
		verbose("\rthread %lu launched", tmp->thid);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		if (pthread_join(tmp->thid, NULL))
		{
			return (0);
		}
		verbose("\rthread %lu finished", tmp->thid);
		tmp = tmp->next;
	}
	if (VERBOSE)
	{
		print_tchain(head);
	}
	tmp = head;
	old_value = head->res;
	while (tmp)
	{
		if (tmp->res != old_value)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (old_value);
	pthread_exit(NULL);
}
