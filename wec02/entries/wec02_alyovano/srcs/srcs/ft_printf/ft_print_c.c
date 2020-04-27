/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:02:23 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/17 14:01:40 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_test_c(t_truc *var, char c)
{
	int champ;

	champ = var->width - 1;
	if (var->flag == '-')
	{
		var->index += ft_putchar_fd(c, 1);
		var->index += ft_while_print(' ', champ);
	}
	else if (var->flag == '0')
	{
		var->index += ft_while_print('0', champ);
		var->index += ft_putchar_fd(c, 1);
	}
	else if (var->flag == 0)
	{
		var->index += ft_while_print(' ', champ);
		var->index += ft_putchar_fd(c, 1);
	}
	return (0);
}

void		ft_print_c(char c, t_truc *var)
{
	if (var->precision == -1 && var->width == 0)
		var->index += ft_putchar_fd(c, 1);
	else
		ft_test_c(var, c);
}
