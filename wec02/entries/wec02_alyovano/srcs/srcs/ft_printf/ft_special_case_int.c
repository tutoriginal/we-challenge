/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_case_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:32:14 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:16:06 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des int dans la joie et la bonne humeur
*/

void			ft_zero_no_preci(t_truc *var, char *str, int neg)
{
	var->index += neg == 1 ? ft_putchar_fd('-', 1) : 0;
	var->index += ft_while_print('0', (var->width - neg) - (int)ft_strlen(str));
	var->index += ft_putstr_fd(str, 1);
}

/*
** Place toutes les valeurs a la bonne tailles en les comparant
** les une aux autres;
*/

void			check_diff(t_truc *var, int neg, char *str)
{
	var->precision = var->precision > (int)ft_strlen(str) ? var->precision : 0;
	var->width = var->precision > 0 ?
	var->width - var->precision : var->width - (int)ft_strlen(str);
	var->precision = var->precision > (int)ft_strlen(str) ?
	var->precision - (int)ft_strlen(str) : 0;
	var->width = neg == 1 ? var->width - 1 : var->width;
}

void			ft_manage_int(t_truc *var, char *str, int neg)
{
	check_diff(var, neg, str);
	if (var->flag != '-')
		var->index += ft_while_print(' ', var->width);
	var->index += neg == 1 ? ft_putchar_fd('-', 1) : 0;
	var->index += ft_while_print('0', var->precision);
	var->index += ft_putstr_fd(str, 1);
	if (var->flag == '-')
		var->index += ft_while_print(' ', var->width);
}

int				ft_traitement_int(t_truc *var, char *str)
{
	int neg;

	neg = *str == '-' && str++ ? 1 : 0;
	if ((var->specif == 'd' || var->specif == 'i')
	&& *str == '0' && var->precision == 0)
	{
		str = "\0";
	}
	else if (var->flag == '0' && var->precision <= -1)
	{
		ft_zero_no_preci(var, str, neg);
	}
	else
	{
		ft_manage_int(var, str, neg);
	}
	return (0);
}
