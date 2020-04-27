/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:08:52 by alyovano          #+#    #+#             */
/*   Updated: 2020/02/03 09:10:31 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_preci_hard(char *str, t_truc *var)
{
	var->index += ft_putstr_fd("0x", 1);
	var->index += ft_while_print('0', (var->precision + 2)
	- (int)ft_strlen(str));
	var->index += ft_putstr_fd(str + 2, 1);
	return (0);
}

/*
** Gestion des int dans la joie et la bonne humeur
*/

void				ft_zero_no_preci_p(t_truc *var, char *str)
{
	var->index += ft_while_print('0', (var->width) - (int)ft_strlen(str));
	var->index += ft_putstr_fd(str, 1);
}

/*
** Place toutes les valeurs a la bonne tailles en les comparant
** les une aux autres;
*/

void				check_diff_p(t_truc *var, char *str)
{
	var->precision = var->precision > (int)ft_strlen(str) ? var->precision : 0;
	var->width = var->precision > 0 ?
	var->width - var->precision : var->width - (int)ft_strlen(str);
	var->precision = var->precision > (int)ft_strlen(str) ?
	var->precision - (int)ft_strlen(str) : 0;
}

void				ft_manage_int_p(t_truc *var, char *str)
{
	check_diff_p(var, str);
	if (var->flag != '-')
		var->index += ft_while_print(' ', var->width);
	var->index += ft_while_print('0', var->precision);
	var->index += ft_putstr_fd(str, 1);
	if (var->flag == '-')
		var->index += ft_while_print(' ', var->width);
}

int					ft_traitement_p_int(t_truc *var, char *str)
{
	if (var->precision == 0)
		var->index += ft_putstr_fd("0x", 1);
	else if (var->precision > (int)ft_strlen(str))
		ft_preci_hard(str, var);
	else if (var->flag == '0' && var->precision == -1)
		ft_zero_no_preci_p(var, str);
	else
		ft_manage_int_p(var, str);
	return (0);
}
