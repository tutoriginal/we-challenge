/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:53:06 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 19:23:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

t_dict	*new_dict(char *word, char *symb)
{
	t_dict	*new;

	new = NULL;
	if (!(new = (t_dict *)malloc(sizeof(t_dict))))
	{
		return (err_ptr("new_dict : malloc fail"));
	}
	new->word = word;
	new->symb = symb;
	return (new);
}

void		del_dict(t_dict *dict)
{
	if (dict->word)
	{
		free(dict->word);
		dict->word = NULL;
	}
	if (dict->symb)
	{
		free(dict->symb);
		dict->symb = NULL;
	}
}

void		clear_dict(t_chain **chain)
{
	t_chain *tmp;

	while (chain && *chain)
	{
		tmp = (*chain)->next;
		del_dict((*chain)->data);
		del_node(*chain);
		*chain = tmp;
	}
}

void		print_node_dict(t_chain *chain)
{
	t_chain	*tmp;
	t_dict	*node;

	tmp = chain;
	if (!tmp)
	{
		puts("NULL NODE");
		return ;
	}
	node = (t_dict *)tmp->data;
	puts("\nNode :");
	printf("[node * %p | word \"%s\" | symbol \"%s\" "\
	"next *> %p]\n", \
	tmp, node->word, node->symb, tmp->next);
}

void		print_chain_dict(t_chain *chain)
{
	t_chain	*tmp;
	t_dict	*node;
	size_t		i;

	tmp = chain;
	i = 0;
	if (!tmp)
	{
		puts("NULL CHAIN");
		return ;
	}
	puts("\nChain :");
	while (tmp)
	{
		node = (t_dict *)tmp->data;
		printf("<%lu> \t [node * %p | word \"%s\" | symbol \"%s\" "\
		"next *> %p]\n", \
		i, tmp, node->word, node->symb, tmp->next);
		i++;
		tmp = tmp->next;
	}
	printf(">> Chain of %lu node(s) <<\n", chain_size(chain));
}
