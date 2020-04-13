/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_human.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:39:31 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 21:39:02 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		ft_translation_to_human(t_morse *morsec)
{
	int i;

	i = -1;
	if (!(morsec->str_fin = calloc(1, sizeof(char))))
		return (0);
	if (!(ft_assignement(morsec, &i)))
		return (0);
	if (!(morsec->str_fin = realloc(morsec->str_fin, i + sizeof(char))))
		return (0);
	morsec->str_fin[i] = '\0';
	return (1);
}

int		ft_strcmp_p2(const char *s1, const char *s2)
{
	size_t	len;
	size_t	len2;
	int		result;

	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (-1);
	else if (s1 && !s2)
		return (1);
	len = ft_strlen(s1) - 1;
	len2 = ft_strlen(s2) + 1;
	len = (len <= len2) ? len : len2;
	result = ft_memcmp(s1 + 2, s2, len);
	return (result);
}

int		ft_xor(t_morse *morsec, int i, int j)
{
	int ret;

	if (ft_strcmp_p2(morsec->alpha[j], morsec->character[i]))
		ret = 0;
	else
		ret = 1;
	if (ft_strcmp(morsec->character[i], "/"))
		return (ret);
	else
		ret = 1;
	return (ret);
}

int		ft_assignement(t_morse *morsec, int *i)
{
	int j;

	while (morsec->character[++*i])
	{
		if (!(morsec->str_fin = realloc(morsec->str_fin, *i + sizeof(char))))
			return (0);
		j = -1;
		while (morsec->alpha[++j])
		{
			if (!(ft_strcmp(morsec->character[*i], "/")))
			{
				morsec->str_fin[*i] = ' ';
				break ;
			}
			else if (!(ft_strcmp_p2(morsec->alpha[j], morsec->character[*i])))
			{
				morsec->str_fin[*i] = morsec->alpha[j][0];
				break ;
			}
		}
		if (!(ft_xor(morsec, *i, j)))
			return (0);
	}
	return (1);
}

int		is_free(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
	{
		free(spt[i++]);
	}
	free(spt);
	return (0);
}
