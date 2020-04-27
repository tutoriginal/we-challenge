/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:46:05 by alyovano          #+#    #+#             */
/*   Updated: 2019/12/10 17:46:16 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned_fd(unsigned n, int fd)
{
	unsigned long	a;

	a = n;
	if (a <= 9)
		ft_putchar_fd(a + 48, fd);
	if (a >= 10)
	{
		ft_putnbr_unsigned_fd(a / 10, fd);
		ft_putchar_fd((a % 10) + 48, fd);
	}
}
