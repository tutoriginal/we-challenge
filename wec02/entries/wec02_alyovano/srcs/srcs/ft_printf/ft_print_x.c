/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:02:59 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:14:51 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des int dans la joie et la bonne humeur
*/

void			ft_zero_no_preci_hexa(t_truc *var, char *str)
{
	var->index += ft_while_print('0', (var->width) - (int)ft_strlen(str));
	var->index += ft_putstr_fd(str, 1);
}

/*
** Place toutes les valeurs a la bonne tailles en les comparant
** les une aux autres;
*/

void			check_diff_hexa(t_truc *var, char *str)
{
	var->precision = var->precision > (int)ft_strlen(str) ? var->precision : 0;
	var->width = var->precision > 0 ?
	var->width - var->precision : var->width - (int)ft_strlen(str);
	var->precision = var->precision > (int)ft_strlen(str) ?
	var->precision - (int)ft_strlen(str) : 0;
}

void			ft_manage_int_hexa(t_truc *var, char *str)
{
	check_diff_hexa(var, str);
	if (var->flag != '-')
		var->index += ft_while_print(' ', var->width);
	var->index += ft_while_print('0', var->precision);
	var->index += ft_putstr_fd(str, 1);
	if (var->flag == '-')
		var->index += ft_while_print(' ', var->width);
}

int				ft_traitement_hexa_int(t_truc *var, char *str)
{
	if (var->specif == 'x' && *str == '0' && var->precision == 0)
		str = "\0";
	if (var->flag == '0' && var->precision <= -1)
		ft_zero_no_preci_hexa(var, str);
	else
		ft_manage_int_hexa(var, str);
	return (0);
}

void			ft_print_x(char *str, t_truc *var)
{
	if (var->specif == 'X')
	{
		str = ft_print_capitalstr(str);
		var->specif = 'x';
	}
	if (var->precision == -1 && var->width == 0)
		var->index += ft_putstr_fd(str, 1);
	else
		ft_traitement_hexa_int(var, str);
	free(str);
}
