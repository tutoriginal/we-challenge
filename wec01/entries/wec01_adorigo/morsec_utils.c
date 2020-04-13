/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 11:42:16 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 21:43:46 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		ft_parsing(t_morse *morsec)
{
	int		i;
	char	*line;

	if (!(morsec->alpha = malloc(sizeof(char*))))
		return (0);
	i = 0;
	while (get_next_line(morsec->fd, &line) > 0)
	{
		if (!(morsec->alpha = realloc(morsec->alpha,
				sizeof(char*) * (i + 1))))
			return (0);
		if (!(morsec->alpha[i] = ft_substr(line, 0, ft_strlen(line))))
			return (is_free(morsec->alpha));
		free(line);
		i++;
	}
	if (!(morsec->alpha = realloc(morsec->alpha, sizeof(char*) * (i + 2))))
		return (0);
	if (!(morsec->alpha[i] = ft_substr(line, 0, ft_strlen(line))))
		return (is_free(morsec->alpha));
	free(line);
	morsec->alpha[i + 1] = NULL;
	return (1);
}

void	free_struct(t_morse *morsec)
{
	if (morsec->alpha)
		is_free(morsec->alpha);
	if (morsec->character)
		is_free(morsec->character);
	if (morsec->str_fin)
	{
		free(morsec->str_fin);
		morsec->str_fin = 0;
	}
}
