/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:31:00 by ancoulon          #+#    #+#             */
/*   Updated: 2020/05/01 10:49:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wec03.h"

/*
* This function is an implementation of the djb2 hashing function
* modified to accept a file path instead of a string.
*/

unsigned long	hash_file(char *path)
{
	int				fd;
	int				c;
	ssize_t			read_bytes;
	unsigned long	hash;
	char			buffer[4096];
	unsigned char	*str;
	size_t			len;

	hash = 5381;
	str = NULL;
	len = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		exit(EXIT_FAILURE);
	while ((read_bytes = read(fd, buffer, sizeof buffer)))
	{
		if (read_bytes < 0)
			exit(EXIT_FAILURE);
		str = realloc(str, len + read_bytes + 1);
		memcpy(str + len, buffer, read_bytes);
		len += read_bytes;
		str[len] = '\0';
	}
	close(fd);
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
