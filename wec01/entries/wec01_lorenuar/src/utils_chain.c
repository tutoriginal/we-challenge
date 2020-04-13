/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:50:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 19:22:53 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

t_chain	*new_node(void *data)
{
	t_chain	*new;

	new = NULL;
	if (!(new = (t_chain*)malloc(sizeof(t_chain))))
	{
		return (err_ptr("new_node : malloc fail"));
	}
	new->data = data;
	new->next = NULL;
	return (new);
}

void		*append_node(t_chain **chain, t_chain *node)
{
	t_chain *tmp;

	tmp = NULL;
	if (!node)
	{
		return (err_ptr("append_node : NULL node"));
	}
	if (*chain)
	{
		tmp = *chain;
		while (node && tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	else if (chain)
	{
		*chain = node;
	}
	return (node);
}

size_t		chain_size(t_chain *chain)
{
	size_t	size;

	size = 0;
	while (chain)
	{
		chain = chain->next;
		size++;
	}
	return (size);
}

void	del_node(t_chain *node)
{
	if (node->data)
	{
		free(node->data);
		node->data = NULL;
	}
	if (node)
	{
		free(node);
		node = NULL;
	}
}

void print_node(t_chain *node)
{
	if (!node)
	{
		puts("NULL NODe");
		return ;
	}
	printf("Node : <%p> | data %p | data \"%s\" | > next %p\n", \
	node, node->data, (char *)node->data, node->next);
}
