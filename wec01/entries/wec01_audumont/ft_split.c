/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 12:12:57 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 19:06:24 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

static int				ft_count(char *str, char *set)
{
	int					count;
	int					is_word;
	int					index;

	index = 0;
	count = 0;
	is_word = 0;
	while (str[index])
	{
		if (!is_word && !ft_inset(str[index], set))
		{
			count++;
			is_word = 1;
		}
		else if (is_word && ft_inset(str[index], set))
			is_word = 0;
		index++;
	}
	return (count);
}

static int				ft_index(char *str, char *set, unsigned int index)
{
	int					isword;
	unsigned int		count;
	unsigned int		pos;

	isword = 0;
	count = 0;
	pos = 0;
	while (str[pos])
	{
		if (!isword && !ft_inset(str[pos], set))
		{
			count++;
			if (count == index + 1)
				break ;
			isword = 1;
		}
		else if (isword && ft_inset(str[pos], set))
			isword = 0;
		pos++;
	}
	return (pos);
}

static char				*ft_word(char *str, char *set)
{
	unsigned int		index;
	unsigned int		len;
	char				*word;

	len = 0;
	index = 0;
	while (str[len] && !ft_inset(str[len], set))
		len++;
	word = (char*)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (index < len)
		word[index++] = *str++;
	word[index] = '\0';
	return (word);
}

static void				ft_free(char **words, int index)
{
	int					index2;

	index2 = 0;
	while (index2 < index)
	{
		free(words[index2]);
		index2++;
	}
	free(words);
}

char					**ft_split(const char *s, char *set)
{
	unsigned int		count_words;
	char				**words;
	unsigned int		index;
	char				*word;

	if (!s)
		return (0);
	count_words = ft_count((char*)s, set);
	word = (char*)s;
	words = (char**)malloc(sizeof(char *) * (count_words + 1));
	if (!words)
		return (0);
	index = 0;
	while (index < count_words)
	{
		words[index] = ft_word(word + ft_index(word, set, index), set);
		if (!words[index])
		{
			ft_free(words, index);
			return (0);
		}
		index++;
	}
	words[index] = 0;
	return (words);
}
