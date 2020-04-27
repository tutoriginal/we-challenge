/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:02:42 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:04:32 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_s(char *str, t_truc *var)
{
	if (!str)
		str = "(null)";
	if (var->precision == -1 && var->width == 0)
		var->index += ft_putstr_fd(str, 1);
	else
		ft_traitement(var, str);
}
