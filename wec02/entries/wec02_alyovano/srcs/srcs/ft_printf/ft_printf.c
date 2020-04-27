/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:58:56 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:02:25 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialise les valeurs de base de la struct a 0;
*/

void			ft_struct_init(t_truc *var)
{
	var->precision = -1;
	var->flag = 0;
	var->width = 0;
	var->specif = 0;
}

/*
** Renvoie vers Etape 1, qui est d'assigner des valeur a ma struct
*/

int				ft_check(t_truc *var, char **format)
{
	(*format)++;
	ft_check_flag(var, format);
	ft_check_width(var, format);
	if (**format == '.')
	{
		var->precision = 0;
		ft_check_precision(var, format);
	}
	if (ft_check_specif(var, format) == 0)
		return (0);
	return (0);
}

/*
** Renvoie vers Etape 2, qui est d'editer l'output  par rapport aux valeurs
** reste a edit le %p
*/

int				ft_edit(t_truc *var)
{
	if (var->specif == '%')
		ft_print_c('%', var);
	else if (var->specif == 'c')
		ft_print_c(va_arg(var->ap, int), var);
	else if (var->specif == 's')
		ft_print_s(va_arg(var->ap, char*), var);
	else if (var->specif == 'p')
		ft_print_p(ft_adress(va_arg(var->ap, char*), var), var);
	else if (var->specif == 'u')
		ft_print_u(ft_itoa_unsigned(va_arg(var->ap, unsigned int)), var);
	else if (var->specif == 'd' || var->specif == 'i')
		ft_print_di(ft_itoa(va_arg(var->ap, int)), var);
	else if (var->specif == 'x' || var->specif == 'X')
		ft_print_x(ft_itoa_base_two(va_arg(var->ap, unsigned int)), var);
	else
		return (0);
	return (1);
}

/*
** Ft_printf, comme le vrai printf
*/

int				ft_printf(const char *format, ...)
{
	t_truc	*var;

	if (!*format || !format || (!(var = malloc(sizeof(t_truc)))))
		return (0);
	var->index = 0;
	va_start(var->ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_struct_init(var);
			ft_check(var, (char**)&format);
			if (ft_edit(var) == 0)
				break ;
		}
		else
			var->index += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(var->ap);
	free((void*)var);
	return (var->index);
}
