/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_morse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:16:02 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 21:53:20 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int	ft_translation_to_morse(t_morse *morsec)
{
	int		i;
	int		j;
	int		len_morse;
	int		len_str;

	if (!(morsec->str_fin = calloc(1, sizeof(char) + 1)))
		return (0);
	i = -1;
	while (morsec->str[++i])
	{
		len_str = ft_strlen(morsec->str_fin);
		j = -1;
		while (morsec->alpha[++j])
		{
			len_morse = ft_strlen(morsec->alpha[j]) - 1;
			if (ft_toupper(morsec->str[i]) == morsec->alpha[j][0])
			{
				if (!(morsec->str_fin = realloc(morsec->str_fin,
						ft_strlen(morsec->str_fin) + len_morse + 1)))
					return (0);
				morsec->str_fin = ft_strjoin(morsec->str_fin,
						ft_substr(morsec->alpha[j], 2, len_morse - 1));
				break ;
			}
			else if (morsec->str[i] == ' ')
			{
				if (!(morsec->str_fin = realloc(morsec->str_fin,
					ft_strlen(morsec->str_fin) + 3)))
					return (0);
				morsec->str_fin = ft_strjoin(morsec->str_fin, "/");
				break ;
			}
		}
		morsec->str_fin = ft_strjoin(morsec->str_fin, " ");
	}
	if (!(morsec->str_fin = realloc(morsec->str_fin, i + sizeof(char))))
		return (0);
	morsec->str_fin = ft_strjoin(morsec->str_fin, "\0");
	return (1);
}
