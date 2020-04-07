/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wec00_marandre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 15:20:37 by martichou         #+#    #+#             */
/*   Updated: 2020/04/07 17:43:39 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pthread.h> 

void *ft_strlen_recu(void *st)
{
	char *str = (char*)st;
    if (*str == 0) pthread_exit(0);
    pthread_exit((void*)(strlen(str + 1) + 1));
}

void *ft_strlen_norm(void *st)
{
	char *str = (char*)st;
	size_t i = 0;
	while (str[i] != '\0') i++;
	pthread_exit((void*)i);
}

void *ft_strlen_wtf(void *st)
{
	char *str = (char*)st;
    size_t i = 0;
    __asm__  (
        "repne scasb\n\t"
        "not %%ecx\n\t"
        "dec %%ecx"
        :"=c" (i), "+D" (str)
        :"c"(-1), "a"(0), "m" (*(const struct {char a; char x[];} *) str)
    );
	pthread_exit((void*)i);
}

void *ft_strlen_dev_random(void *st)
{
	char *str = (char*)st;
	size_t	i = 0;
	int		ret;
	char	buf[512];

	int fd = open("/dev/urandom", O_RDONLY);
	while (i < strlen(str) && (ret = read(fd, buf, 512)))
	{
		buf[ret] = '\0';
		for (size_t x = 1; x < strlen(str); x++) if (buf[x] == str[i++]) break; else i--;
	}
	close(fd);
	pthread_exit((void*)i);
}

size_t ft_strlen(char *str)
{
	void *size_strlen, *size_strlen_recu, *size_strlen_norm, *size_strlen_wtf, *size_strlen_dev_random;
	pthread_t tid;
	pthread_create(&tid, NULL, (void*)strlen, (void*)str);
	pthread_join(tid, &size_strlen);
	pthread_create(&tid, NULL, ft_strlen_recu, (void *)str);
	pthread_join(tid, &size_strlen_recu);
	pthread_create(&tid, NULL, ft_strlen_norm, (void *)str);
	pthread_join(tid, &size_strlen_norm);
	pthread_create(&tid, NULL, ft_strlen_wtf, (void *)str);
	pthread_join(tid, &size_strlen_wtf);
	pthread_create(&tid, NULL, ft_strlen_dev_random, (void *)str);
	pthread_join(tid, &size_strlen_dev_random);
	
	return (((int)size_strlen + (int)size_strlen_recu + (int)size_strlen_norm + (int)size_strlen_wtf + (int)size_strlen_dev_random) / (1 + 1 + 1 + 1 + 1));
}
