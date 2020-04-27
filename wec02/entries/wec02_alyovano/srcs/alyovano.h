/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alyovano.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:22:23 by alyovano          #+#    #+#             */
/*   Updated: 2020/02/18 11:56:33 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALYOVANO_H
# define ALYOVANO_H
# include "./srcs/ft_printf/ft_printf.h"
# include "./srcs/libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);

#endif
