/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 22:57:04 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 16:44:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

size_t		hasto(char *s, char c)
{
	size_t	to;

	to = 0;
	while (s && s[to])
	{
		if (s[to] == c)
			return (to + 1);
		to++;
	}
	if (s && s[to] == c)
		return (to + 1);
	return (0);
}

char	*jointo(char *s1, char *s2, char **tofree)
{
	char	*a;
	size_t	sl1;
	size_t	sl2;
	size_t	i;

	a = NULL;
	sl1 = hasto(s1, '\0');
	sl2 = hasto(s2, '\0');
	if (!(a = (char *)malloc((sl1 + sl2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (sl1 && s1 && *s1 && *s1 != '\n')
		a[i++] = *s1++;
	while (sl2 && s2 && *s2 && *s2 != '\n')
		a[i++] = *s2++;
	a[i] = '\0';
	if (tofree && *tofree)
	{
		free(*tofree);
		*tofree = NULL;
	}
	return (a);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		ret;
	size_t		i;

	ret = 1;
	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FOPEN_MAX
			|| !line || !(*line = jointo(buf, NULL, NULL)))
		return (-1);
	while (!hasto(buf, '\n') && ret)
	{
		if ((ret = read(fd, &buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (!(*line = jointo(*line, buf, line)))
			return (-1);
	}
	ret = hasto(buf, '\n');
	if (ret == 0)

		return (0);
	while (buf[ret] && ret)
		buf[i++] = buf[ret++];
	buf[i] = '\0';
	return (1);
}
