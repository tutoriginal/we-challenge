/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:45:03 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/12 21:25:57 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORSEC_H
# define MORSEC_H
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct	s_morse
{
	int			fd;
	char		**alpha;
	char		**character;
	char		*str_fin;
	char		*str;
}				t_morse;

int				is_free(char **spt);
int				ft_parsing(t_morse *morsec);
int				ft_strcmp_p2(const char *s1, const char *s2);
int				ft_translation_to_human(t_morse *morsec);
int				ft_translation_to_morse(t_morse *morsec);
int				ft_xor(t_morse *morsec, int i, int j);
void			free_struct(t_morse *morsec);
int				ft_assignement(t_morse *morsec, int *i);

#endif
