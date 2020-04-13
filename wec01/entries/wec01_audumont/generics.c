/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:37:21 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 19:04:09 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

void		ft_init(t_final *t_strf)
{
	if (!(t_strf->strf = (char*)malloc(sizeof(char))))
		t_strf->ok = 0;
	else
	{
		t_strf->ok = 1;
		bzero(t_strf->strf, 1);
	}
}

void		ft_stradd(t_final *t_strf, char *stradd)
{
	char	*tmp;

	tmp = strdup(t_strf->strf);
	free(t_strf->strf);
	t_strf->strf = ft_strjoin(tmp, stradd);
	free(tmp);
}

int			ft_error(int error)
{
	if (error == 1)
		printf("Invalid letter\n");
	if (error == 2)
		printf("Invalid format : not a morse input");
	if (error == 3)
		printf("Error : no arguments to translate");
	if (error == 4)
		printf("Invalid format : not an alpha input");
	return (0);
}
