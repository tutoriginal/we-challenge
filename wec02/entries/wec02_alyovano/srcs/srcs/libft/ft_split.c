/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:15:02 by alyovano          #+#    #+#             */
/*   Updated: 2019/11/01 16:33:38 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_elems(char *str, char c)
{
	int i;
	int number;

	i = 0;
	number = 0;
	if (str[0] == '\0')
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		number++;
		while (str[i] != c && str[i])
			i++;
	}
	if (str[i - 1] == c)
		number--;
	return (number);
}

static int		ft_size(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char		*ft_fill_tab(char *tab, char *str, char c)
{
	int i;
	int len;

	len = ft_size(str, c);
	i = 0;
	if (!(tab = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char		**ft_free(char **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_nbr_elems((char *)s, c);
	if (!(result = (char**)malloc((len + 1) * sizeof(char*))))
		return (NULL);
	while (i < len && s[j] != '\0')
	{
		while (s[j] == c && s[j] != '\0')
			++j;
		if (!(result[i] = ft_fill_tab(result[i], (char *)&s[j], c)))
			return (ft_free(result, i));
		j += ft_size((char *)&s[j], c);
		i++;
	}
	result[len] = 0;
	return (result);
}
