/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 11:33:23 by macbook           #+#    #+#             */
/*   Updated: 2020/04/12 21:40:40 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORSEC_H
# define MORSEC_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# define MORSE "./-"
# define ISSPACES "\t\r\v\f "

# define TANK "**ETIANMSURWDKGOHVF*L*PJBXCYZQ**"

typedef	struct	s_final
{
	char		*strf;
	int			ok;
}				t_final;

/*
 ** GENERIC FUNCTIONS
*/

int				ft_error(int error);
void			ft_init(t_final *t_fstr);

/*
 ** MORSE TO STRING CONVERSIONS FUNCTIONS
*/

int				ft_letters(char *words, t_final *t_strf);
int				ft_set_check(char c, char *set);
int				ft_is_morse_valid(char	*str);

/*
 ** STRING TO MORSE CONVERSIONS FUNCTIONS
*/

int				ft_string_to_morse(char *str);
void			ft_u_to_z(char c, t_final *t_fstr);

/*
 ** UTILS
*/

char			**ft_split(const char *s, char *sep);
int				ft_inset(char c, char *set);
char			*ft_strjoin(const char *s1, char const *s2);
void			ft_stradd(t_final *t_strf, char *stradd);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
char			*ft_c_to_str(char c);

#endif
