/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:44:28 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 21:43:27 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int			ft_to_human(char *str, t_morse *morsec)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_haschr("-./ ", str[i]))
			return (-1);
	}
	if (!(morsec->character = ft_split(str, ' ')))
		return (-1);
	if (!ft_parsing(morsec))
		return (-1);
	if (!ft_translation_to_human(morsec))
		return (-2);
	ft_printf("%s\n", morsec->str_fin);
	return (0);
}

int			ft_to_morse(t_morse *morsec)
{
	int i;

	i = -1;
	morsec->character = NULL;
	if (!ft_parsing(morsec))
		return (-1);
	if (!ft_translation_to_morse(morsec))
		return (-2);
	ft_printf("%s\n", morsec->str_fin);
	return (0);
}

int			main(int ac, char **av)
{
	int		ret;
	t_morse	morsec;

	morsec.fd = open("./dictionary.txt", O_RDONLY);
	if (ac == 2)
		ret = ft_to_human(av[1], &morsec);
	else if (ac == 3)
	{
		morsec.str = av[2];
		if (!ft_strcmp(av[1], "-r"))
			ret = ft_to_morse(&morsec);
		else
			ret = -1;
	}
	else
		return (printf("there are either too many, %s\n",
				"or too few arguments to the program call"));
	if (ret == -1 || ret == -2)
		return (ft_printf("an error occured \n"));
	close(morsec.fd);
	free_struct(&morsec);
	ft_printf("%d\n", ret);
	return (ret);
}
