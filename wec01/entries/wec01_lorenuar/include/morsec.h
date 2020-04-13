/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:53 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 18:42:33 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MORSEC_H
# define MORSEC_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define BLANK "\t\v\f\r "
# define MORSE_DICT ".-"
# define MORSE "\t\v\f\r /.-"
# define MORSE_SEP "/"

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>

struct s_dict
{
	char				*word;
	char				*symb;
};
typedef struct s_dict 	t_dict;

struct s_chain
{
	void				*data;
	struct s_chain 		*next;
};
typedef struct s_chain 	t_chain;

/*
** dict utils
*/
t_dict		*new_dict(char *word, char *symb);
void		del_dict(t_dict *dict);
void		clear_dict(t_chain **chain);
void		print_chain_dict(t_chain *chain);
void		print_node_dict(t_chain *chain);

/*
** trsl utils
*/
void		print_chain_trsl(t_chain *chain);
void		print_node_trsl(t_chain *chain);
void		clear_trsl(t_chain **chain);
char		*get_by_symbol(t_chain *chain, char *symb);
char		*get_by_word(t_chain *chain, char *word);
char		*to_str(t_chain *trsl);
int			check_input(char *s, char *t);
char		*translator(t_chain *dict, char *input);
char		*rev_translator(t_chain *dict, char *input);

/*
** chain utils
*/
t_chain		*new_node(void *data);
void		*append_node(t_chain **chain, t_chain *node);
size_t		chain_size(t_chain *chain);
void		del_node(t_chain *node);
void 		print_node(t_chain *node);

/*
** get_next_line
*/
int			get_next_line(int fd, char **line);
size_t		hasto(char *s, char c);
char		*jointo(char *s1, char *s2, char **tofree);

/*
** string utils
*/
size_t		str_len(char *s);
size_t		str_lento(char *s, char *t);
size_t		str_revlento(char *s, char *t);
char		*str_ndup(char *s, size_t n);
char		*str_dup(char *s);
char		*str_dupto(char *s, char *t);
char		*str_revdupto(char *s, char *t);
int			is_only(char c, char *t);
size_t		str_cmp(char *s1, char *s2);
char		*str_low(char *s);
char		*str_upp(char *s);
int			is_space(char c);
int			is_lower(char c);
int			is_upper(char c);
char		to_lower(char c);
char		to_upper(char c);
int			is_letter(char c);
char		toggle_case(char c);

/*
** print utils
*/
void		putchar_fd(int fd, char c);
void		putstr_fd(int fd, char *s);
int			err(char *s);
void		*err_ptr(char *s);
void		str_del(char **tofree);

/*
** core functions
*/
char		*translator(t_chain *dict, char *input);
t_chain		*get_dict(char *filename);

#endif
