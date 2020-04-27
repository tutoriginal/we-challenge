/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:59:01 by alyovano          #+#    #+#             */
/*   Updated: 2020/02/18 11:33:22 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef	struct
{
	int				precision;
	char			flag;
	int				width;
	char			specif;
	va_list			ap;
	int				index;
}					t_truc;

void				ft_check_flag(t_truc *var, char **format);
void				ft_check_width(t_truc *var, char **format);
void				ft_check_precision(t_truc *var, char **format);
int					ft_check_specif(t_truc *var, char **specif);
int					ft_printf(const char *format, ...);

/*
** Fonction de traitement
**	|	|	|	|	|	|
**	v	v	v	v	v	v
*/

void				ft_print_c(char c, t_truc *var);
void				ft_print_s(char *str, t_truc *var);
void				ft_print_x(char *str, t_truc *var);
void				ft_print_di(char *str, t_truc *var);
void				ft_print_u(char *str, t_truc *var);
void				ft_print_p(char *str, t_truc *var);

/*
** Fonction de precision & Flags
**	|	|	|	|	|	|	|	|
**	v	v	v	v	v	v	v	v
*/

int					ft_traitement(t_truc *var, char *str);
int					ft_traitement_int(t_truc *var, char *str);
int					ft_traitement_unsigned_int(t_truc *var, char *str);
void				ft_flag_c(t_truc *var, int champ, char c);
int					ft_traitement_hexa_int(t_truc *var, char *str);
int					ft_traitement_p_int(t_truc *var, char *str);

/*
** Fonction specifiques
**	|	|	|	|	|
**	v	v	v	v	v
*/

char				*ft_adress(char *str, t_truc *var);
int					ft_test_c(t_truc *var, char c);

#endif
