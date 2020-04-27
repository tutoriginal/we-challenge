/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:02:34 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/20 09:55:35 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_di(char *str, t_truc *var)
{
	if (*str == '0' && var->width > (int)ft_strlen(str) && var->precision == 0)
	{
		ft_while_print(' ', var->width);
	}
	else if (var->precision == -1 && var->width == 0)
		var->index += ft_putstr_fd(str, 1);
	else
		ft_traitement_int(var, str);
	free(str);
}
