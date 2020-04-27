/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:54:56 by alyovano          #+#    #+#             */
/*   Updated: 2020/02/03 09:10:51 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_adress(char *str, t_truc *var)
{
	long long unsigned	adress;
	char				*hexa;

	(void)var;
	adress = (long long unsigned)str;
	if (!str)
	{
		hexa = NULL;
		free(str);
		return (ft_strdup("0x0"));
	}
	else
	{
		hexa = ft_utoa(adress);
	}
	return (hexa);
}

void				ft_print_p(char *str, t_truc *var)
{
	if (var->precision == -1 && var->width == 0)
	{
		var->index += ft_putstr_fd(str, 1);
	}
	else
		ft_traitement_p_int(var, str);
	free(str);
}
