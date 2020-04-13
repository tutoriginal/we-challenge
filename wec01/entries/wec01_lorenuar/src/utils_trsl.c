/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trsl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:45:45 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 19:06:36 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

char	*get_by_symbol(t_chain *chain, char *symb)
{
	t_dict	*tmp;

	tmp = NULL;
	if (!str_cmp(symb, BLANK))
	{
		return (NULL);
	}
	else if (!str_cmp(symb, MORSE_SEP))
	{
		return (strdup(" "));
	}
	else
	{
		while (chain)
		{
			tmp = (t_dict *)chain->data;
			if (str_cmp(symb, tmp->symb))
			{
				chain = chain->next;
			}
			else if (!str_cmp(symb, tmp->symb))
			{
				return (str_dup(tmp->word));
			}
		}
	}
	return (NULL);
}

char	*get_by_word(t_chain *chain, char *word)
{
	t_dict	*tmp;

	tmp = NULL;
	if (check_input(word,BLANK))
	{
		return (str_dup(MORSE_SEP));
	}
	else
	{
		while (chain)
		{
			tmp = (t_dict *)chain->data;
			if (str_cmp(word, tmp->word))
			{
				chain = chain->next;
			}
			else if (!str_cmp(word, tmp->word))
			{
				return (str_dup(tmp->symb));
			}
		}
	}
	return (NULL);
}

void		clear_trsl(t_chain **chain)
{
	t_chain *tmp;

	while (chain && *chain)
	{
		tmp = (*chain)->next;
		del_node(*chain);
		*chain = tmp;
	}
}

void		print_chain_trsl(t_chain *chain)
{
	t_chain	*tmp;
	size_t		i;

	tmp = chain;
	i = 0;
	if (!tmp)
	{
		puts("NULL CHAIN");
		return ;
	}
	puts("\nChain TRSL:");
	while (tmp)
	{
		printf("<%lu> \t [node * %p | trsl \"%s\" *%p |next *> %p]\n", \
		i, tmp, (char *)tmp->data, tmp->data, tmp->next);
		i++;
		tmp = tmp->next;
	}
	printf(">> Chain of %lu node(s) <<\n", chain_size(chain));
}

void		print_node_trsl(t_chain *chain)
{
	t_chain	*tmp;

	tmp = chain;
	if (!tmp)
	{
		puts("NULL NODE");
		return ;
	}
	puts("\nNode TRSL :");
	printf("[node * %p | trsl  \"%s\" next *> %p]\n", \
	tmp, (char *)tmp->data, tmp->next);
}
