/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_special_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:34 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:05:32 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_hard_case(t_truc *var, char *str, int champ)
{
	if (var->flag == '-')
	{
		var->index += ft_putstr_len(str, var->precision);
		var->index += ft_while_print(' ', champ);
	}
	else if (var->flag == '0')
	{
		var->index += ft_while_print('0', champ);
		var->index += ft_putstr_len(str, var->precision);
	}
	else if (var->flag == 0)
	{
		var->index += ft_while_print(' ', champ);
		var->index += ft_putstr_len(str, var->precision);
	}
}

void			ft_simple_case(t_truc *var, char *str, int champ)
{
	if (var->flag == '-' && var->precision == -1)
	{
		var->index += ft_putstr_fd(str, 1);
		var->index += ft_while_print(' ', champ);
	}
	else if (var->flag == '0' && var->precision == -1)
	{
		var->index += ft_while_print('0', champ);
		var->index += ft_putstr_fd(str, 1);
	}
	else if (var->flag == 0 && var->precision == -1)
	{
		var->index += ft_while_print(' ', champ);
		var->index += ft_putstr_fd(str, 1);
	}
}

int				ft_traitement(t_truc *var, char *str)
{
	int champ;

	champ = 0;
	if (var->precision < -1)
		var->precision = ft_strlen(str);
	if ((int)ft_strlen(str) <= var->width && var->precision == -1)
	{
		champ = var->width - ft_strlen(str);
		ft_simple_case(var, str, champ);
	}
	else if ((int)ft_strlen(str) > var->width && var->precision == -1)
		var->index += ft_putstr_len(str, var->precision);
	if (var->precision != -1)
	{
		if (var->precision > (int)ft_strlen(str))
			champ = var->width - ft_strlen(str);
		else
			champ = var->width - var->precision;
		ft_hard_case(var, str, champ);
	}
	return (0);
}
