/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:22:00 by alyovano          #+#    #+#             */
/*   Updated: 2019/10/29 16:45:38 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(char c)
{
	if ((c == '\t' || c == '\n'
			|| c == '\v' || c == '\f'
			|| c == '\r' || c == ' '))
		return (1);
	return (0);
}

static	int		ft_result(unsigned int result, int valeur)
{
	if (result > 2147483647 && valeur == 1)
		return (-1);
	if (result > 2147483648 && valeur == -1)
		return (0);
	return (int)(result * valeur);
}

int				ft_atoi(const char *str)
{
	int				i;
	int				valeur;
	unsigned int	result;

	i = 0;
	valeur = 1;
	result = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) > 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valeur = valeur * -1;
		i++;
	}
	while (str[i] >= '0' && '9' >= str[i])
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	return (ft_result(result, valeur));
}
