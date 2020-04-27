/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:29:21 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 10:47:32 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_check_flag(t_truc *var, char **format)
{
	char minus;
	char zero;

	minus = 0;
	zero = 0;
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			minus = 1;
		if (**format == '0')
			zero = 1;
		(*format)++;
	}
	if (minus == 1)
		var->flag = '-';
	if (minus == 0 && zero == 1)
		var->flag = '0';
	if (minus == 0 && zero == 0)
		var->flag = 0;
}

void				ft_check_width(t_truc *var, char **format)
{
	if (**format == '*')
	{
		var->width = va_arg(var->ap, int);
		if (var->width < 0)
			var->flag = '-';
		(*format)++;
	}
	else
	{
		var->width = ft_atoi(*format);
		*format += ft_intlen(var->width);
	}
	if (var->width < 0)
		var->width *= -1;
}

void				ft_check_precision(t_truc *var, char **format)
{
	(*format)++;
	if (**format == '*')
	{
		var->precision = va_arg(var->ap, int);
		(*format)++;
		return ;
	}
	while (**format == '0')
		(*format)++;
	if (ft_isdigit(**format) == 1)
	{
		var->precision = ft_atoi(*format);
		*format += ft_intlen(var->precision);
	}
}

int					ft_check_specif(t_truc *var, char **format)
{
	if (ft_isprintf(**format) == 1)
	{
		var->specif = **format;
		return (1);
	}
	else
		return (0);
}
