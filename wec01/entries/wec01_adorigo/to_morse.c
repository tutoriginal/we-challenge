/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_morse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:16:02 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 22:32:54 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int	ft_translation_to_morse(t_morse *morsec)
{
	int		i;
	int		j;
	int		len_morse;
	char	*temp;
	char	*tmp;

	if (!(morsec->str_fin = calloc(1, sizeof(char) + 1)))
		return (0);
	i = -1;
	while (morsec->str[++i])
	{
		j = -1;
		while (morsec->alpha[++j])
		{
			len_morse = ft_strlen(morsec->alpha[j]) - 1;
			if (ft_toupper(morsec->str[i]) == morsec->alpha[j][0])
			{
				temp = ft_strdup(morsec->str_fin);
				free(morsec->str_fin);
				morsec->str_fin = ft_strjoin(temp,
						(tmp = ft_substr(morsec->alpha[j], 2, len_morse - 1)));
				free(temp);
				free(tmp);
				break ;
			}
			else if (morsec->str[i] == ' ')
			{
				temp = ft_strdup(morsec->str_fin);
				free(morsec->str_fin);
				morsec->str_fin = ft_strjoin(temp, "/");
				free(temp);
				break ;
			}
		}
		temp = ft_strdup(morsec->str_fin);
		free(morsec->str_fin);
		morsec->str_fin = ft_strjoin(temp, " ");
		free(temp);
	}
	temp = ft_strdup(morsec->str_fin);
	free(morsec->str_fin);
	morsec->str_fin = ft_strjoin(temp, "\0");
	free(temp);
	return (1);
}
