/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:46:52 by alyovano          #+#    #+#             */
/*   Updated: 2020/02/18 11:51:08 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../alyovano.h"
#define BUFFER_SIZE 32

static int		ft_scann_gnl(const char *s)
{
	int pos;

	pos = 0;
	while (s && s[pos])
	{
		if (s[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

static char		*ft_strjoin_free_gnl(char *s1, char *buf)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] && s1[i] != '\n')
		i++;
	while (buf && buf[j] && buf[j] != '\n')
		j++;
	tab = malloc(i + j + 1);
	i = 0;
	j = 0;
	while (s1 && s1[j] && s1[j] != '\n')
		tab[i++] = s1[j++];
	while (buf && *buf && *buf != '\n')
		tab[i++] = *buf++;
	tab[i] = 0;
	free(s1);
	return (tab);
}

int				get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				ret;
	int				i;

	if (!line || !(*line = ft_strjoin_free_gnl(NULL, buf)))
		return (-1);
	ret = 1;
	while (ft_scann_gnl(buf) == -1 && ret && ret != -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		*line = ft_strjoin_free_gnl(*line, buf);
	}
	i = 0;
	if (!buf[0])
		return (0);
	ret = ft_scann_gnl(buf) + 1;
	while (buf[i] && buf[ret])
		buf[i++] = buf[ret++];
	buf[i] = 0;
	return (1);
}
