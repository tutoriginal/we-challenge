/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:02:47 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/20 09:55:44 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_zero_no__preci(t_truc *var, char *str, int neg)
{
	var->index += neg == 1 ? ft_putchar_fd('-', 1) : 0;
	var->index += ft_while_print('0', (var->width - neg) - (int)ft_strlen(str));
	var->index += ft_putstr_fd(str, 1);
}

/*
** Place toutes les valeurs a la bonne tailles en les comparant
** les une aux autres;
*/

void			check_unsigned_diff(t_truc *var, int neg, char *str)
{
	var->precision = var->precision > (int)ft_strlen(str) ? var->precision : 0;
	var->width = var->precision > 0 ?
	var->width - var->precision : var->width - (int)ft_strlen(str);
	var->precision = var->precision > (int)ft_strlen(str) ?
	var->precision - (int)ft_strlen(str) : 0;
	var->width = neg == 1 ? var->width - 1 : var->width;
}

void			ft_manage_unsigned_int(t_truc *var, char *str, int neg)
{
	check_unsigned_diff(var, neg, str);
	if (var->flag != '-')
		var->index += ft_while_print(' ', var->width);
	var->index += neg == 1 ? ft_putchar_fd('-', 1) : 0;
	var->index += ft_while_print('0', var->precision);
	var->index += ft_putstr_fd(str, 1);
	if (var->flag == '-')
		var->index += ft_while_print(' ', var->width);
}

/*
** reste a gerer les unsigned int extreme MAX / MIN ft_test_c
*/

int				ft_traitement_unsigned_int(t_truc *var, char *str)
{
	int neg;

	neg = *str == '-' && str++ ? 1 : 0;
	if ((var->specif == 'p' || var->specif == 'u')
	&& *str == '0' && var->precision == 0)
	{
		str = "\0";
	}
	else if (var->flag == '0' && var->precision <= -1)
		ft_zero_no__preci(var, str, neg);
	else
		ft_manage_unsigned_int(var, str, neg);
	return (0);
}

void			ft_print_u(char *str, t_truc *var)
{
	if (*str == '0' && var->width > (int)ft_strlen(str) && var->precision == 0)
	{
		ft_while_print(' ', var->width);
	}
	else if (var->precision == -1 && var->width == 0)
		var->index += ft_putstr_fd(str, 1);
	else
		ft_traitement_unsigned_int(var, str);
	free(str);
}
