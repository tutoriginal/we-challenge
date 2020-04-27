/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:51:54 by alyovano          #+#    #+#             */
/*   Updated: 2019/11/01 14:54:08 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		size;
	char				*str;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		str[size] = (*f)(size, s[size]);
		size++;
	}
	str[size] = '\0';
	return (str);
}
