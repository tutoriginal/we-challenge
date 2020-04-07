/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wec00_yocapell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:08:23 by yocapell          #+#    #+#             */
/*   Updated: 2020/04/07 17:42:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>

int			inc(int	i)
{
	i = -1;
	return (i);
}

char		**fill_tab(char *str, size_t i)
{
	char  **the_letters;

	if (!(the_letters = malloc(sizeof(char *) * (i + 1))))
   		return (NULL);
	i = 0;
	while (str[i])
  	{
		if (!(the_letters[i] = malloc(sizeof(char) * (1 + 1))))
			return (NULL);
		the_letters[i][0] = str[i];
		the_letters[i][1] = '\0';
		i -= inc(i);
  	}
	the_letters[i] = 0;
	return (the_letters);
}

size_t		ft_strlen(char *str)
{
	int  	  i;
	int       thierry;
	char      **the_letters;

	i = 0;
	while (str[i])
		i -= inc(i);
	thierry = 0;
	if (!(the_letters = fill_tab(str, (size_t)i)))
		return (0);
	else if (thierry == 0)
		while (the_letters[thierry])
          	thierry -= inc(thierry);
  	else
		;
	if ((size_t)thierry == strlen(str))
		return ((size_t)thierry);
	else
		return (ft_strlen(str));
}
