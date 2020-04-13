/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:24:08 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 16:51:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

size_t	str_len(char *s)
{
	size_t len;

	len = 0;
	while (s && s[len])
	len++;
	return (len);
}

size_t	str_lento(char *s, char *t)
{
	size_t	lento;

	lento = 0;
	while (s && s[lento] && !is_only(s[lento], t))
	{
		lento++;
	}
	if (s && is_only(s[lento], t))
	{
		return (lento);
	}
	return (lento);
}

size_t	str_revlento(char *s, char *t)
{
	size_t	lento;
	size_t	slen;

	slen = str_len(s);
	lento = slen;
	while (s && s[lento] && is_only(s[lento], t))
	{
		lento--;
	}
	return (lento);
}

char	*str_ndup(char *s, size_t n)
{
	char	*new;
	size_t	lento;
	size_t	i;

	i = 0;
	lento = str_len(s);
	if (!(new = malloc(lento + 1 * sizeof(char))))
	{
		return (NULL);
	}
	while (s && *s && i < lento && i < n)
	{
		new[i++] = *s++;
	}
	new[i] = '\0';
	return (new);
}

char	*str_dup(char *s)
{
	char	*new;
	size_t	lento;
	size_t	i;

	i = 0;
	lento = str_len(s);
	if (!(new = malloc(lento + 1 * sizeof(char))))
	{
		return (NULL);
	}
	while (s && *s && i < lento)
	{
		new[i++] = *s++;
	}
	new[i] = '\0';
	return (new);
}

char	*str_dupto(char *s, char *t)
{
	char	*new;
	size_t	lento;
	size_t	i;

	i = 0;
	lento = str_lento(s, t);
	if (!(new = malloc(lento + 1 * sizeof(char))))
	{
		return (NULL);
	}
	while (s && *s && i < lento)
	{
		new[i++] = *s++;
	}
	new[i] = '\0';
	return (new);
}

char	*str_revdupto(char *s, char *t)
{
	char	*new;
	size_t	lento;
	size_t	i;

	lento = str_revlento(s, t);
	i = 0;
	if (!(new = malloc(lento + 1 * sizeof(char))))
	{
		return (NULL);
	}
	while (s && *s && !is_only(*s, t))
	{
		s++;
	}
	while (s && *s && is_only(*s, t))
	{
		s++;
	}
	while (s && *s && i < lento && !is_only(*s, t))
	{
		new[i++] = *s++;
	}
	new[i] = '\0';
	return (new);
}

inline int	is_space(char c)
{
	return (((c == ' ' || (c >= '\t' && c <= '\r')) ? 1 : 0));
}

inline int	is_lower(char c)
{
	return (((c >= 'a' && c <= 'z') ? 1 : 0));
}

inline int	is_upper(char c)
{
	return (((c >= 'A' && c <= 'Z') ? 1 : 0));
}

inline char	to_lower(char c)
{
	return((is_upper(c)) ? c + ('a' - 'A') : c);
}

inline char	to_upper(char c)
{
	return((is_lower(c)) ? c - ('a' - 'A') : c);
}

int		is_letter(char c)
{
	if (is_lower(c) && c == to_upper(c))
	{
		return (1);
	}
	else if (is_upper(c) && c == to_lower(c))
	{
		return (1);
	}
	return (0);
}

char	toggle_case(char c)
{
	if (is_lower(c) && c == to_upper(c))
	{
		return (to_upper(c));
	}
	else if (is_upper(c) && c == to_lower(c))
	{
		return (to_lower(c));
	}
	return (0);
}

char	*str_low(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		s[i] = to_lower(s[i]);
		i++;
	}
	return (s);
}

char	*str_upp(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		s[i] = to_upper(s[i]);
		i++;
	}
	return (s);
}

int		is_only(char c, char *t)
{
	while (t && *t)
	{
		if (*t == c)
		{
			return (1);
		}
		t++;
	}
	return (0);
}

void	putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	putstr_fd(int fd, char *s)
{
	write(fd, s, str_len(s));
}

int		err(char *s)
{
	putstr_fd(2, "\033[31;1mError : ");
	putstr_fd(2, s);
	putstr_fd(2, "\033[0m");
	putchar_fd(2, '\n');
	return (1);
}

void	*err_ptr(char *s)
{
	putstr_fd(2, "\033[31;1mError : ");
	putstr_fd(2, s);
	putstr_fd(2, "\033[0m");
	putchar_fd(2, '\n');
	return (NULL);
}

void	str_del(char **tofree)
{
	if (tofree && *tofree)
	{
		free(*tofree);
		*tofree = NULL;
	}
}

size_t	str_cmp(char *s1, char *s2)
{
	size_t 	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		//printf("CMP <%lu> '%c' ?=? '%c'\n",i, s1[i], s2[i]);
		i++;
	}
	//printf("CMP-RET : <%lu> '%c' ?=? '%c'\n",i, s1[i], s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
