/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:42:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/12 21:05:37 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORSEC_H
# define MORSEC_H
# define BUFFER_SIZE 32
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_wav_header
{
	char	riff_tag[4];
	int		riff_length;
	char	wave_tag[4];
	char	fmt_tag[4];
	int		fmt_length;
	short	audio_format;
	short	num_channels;
	int		sample_rate;
	int		byte_rate;
	short	block_align;
	short	bits_per_sample;
	char	data_tag[4];
	int		data_length;
}					t_wav;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** chained_lists.c
*/

void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(void *content);

/*
** get_next_line.c
*/

int					get_next_line(int fd, char **line);

/*
** wav.c
*/

void				ft_wav(const char *str);

#endif
